# =========================
# Project configuration
# =========================
LIB_NAME    := cdatastructures

# --- Platform Detection ---
UNAME_S     := $(shell uname -s)

PLATFORM    := linux
SHARED_EXT  := so




ifneq (,$(findstring MINGW,$(UNAME_S)))
    PLATFORM := windows
    SHARED_EXT := dll
endif

ifeq ($(UNAME_S),Darwin)
    PLATFORM := macos
    SHARED_EXT := dylib
endif


ifeq ($(PLATFORM),windows)
    PREFIX ?= /mingw64
else
    PREFIX ?= /usr/local
endif


# --- Artifact Names ---
LIB_STATIC  := lib$(LIB_NAME).a

ifeq ($(PLATFORM),windows)
    SHARED_LIB     := $(LIB_NAME).$(SHARED_EXT)
    IMPORT_LIB    := lib$(LIB_NAME).dll.a
    SHARED_LDFLAGS := -shared
else ifeq ($(PLATFORM),macos)
    SHARED_LIB     := lib$(LIB_NAME).$(SHARED_EXT)
    SHARED_LDFLAGS := -dynamiclib -install_name $(LIBDIR)/$(SHARED_LIB)
else
    SHARED_LIB     := lib$(LIB_NAME).$(SHARED_EXT)
    SHARED_LDFLAGS := -shared
endif

# --- Toolchain ---
CC          ?= gcc
AR          ?= ar
CFLAGS      := -Wall -Wextra -Wpedantic -std=c11 -O2

ifeq ($(PLATFORM),windows)
    # no -fPIC on Windows
else
    CFLAGS += -fPIC
endif

INCLUDEDIR  := $(PREFIX)/include
LIBDIR      := $(PREFIX)/lib
PKGCONFIGDIR:= $(LIBDIR)/pkgconfig

SRC_DIR     := src
INC_DIR     := include
TEST_DIR    := tests

# =========================
# Source discovery
# =========================
SOURCES := $(shell find $(SRC_DIR) -name "*.c" ! -name "*_ll.c")
OBJECTS := $(SOURCES:.c=.o)

# =========================
# Build rules
# =========================
all: $(LIB_STATIC) $(SHARED_LIB)

$(LIB_STATIC): $(OBJECTS)
	$(AR) rcs $@ $^

$(SHARED_LIB): $(OBJECTS)
ifeq ($(PLATFORM),windows)
	$(CC) $(SHARED_LDFLAGS) -o $@ $^ \
	    -Wl,--out-implib,$(IMPORT_LIB)
else
	$(CC) $(SHARED_LDFLAGS) -o $@ $^
endif

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# =========================
# Install / uninstall
# =========================
install: all
	@echo "Installing libraries..."
	install -d $(DESTDIR)$(LIBDIR)
	install -m 644 $(LIB_STATIC) $(DESTDIR)$(LIBDIR)
	install -m 755 $(SHARED_LIB) $(DESTDIR)$(LIBDIR)

ifeq ($(PLATFORM),windows)
	install -m 644 $(IMPORT_LIB) $(DESTDIR)$(LIBDIR)
endif

	@echo "Installing headers..."
	install -d $(DESTDIR)$(INCLUDEDIR)/cdatastructures
	install -m 644 $(INC_DIR)/*.h $(DESTDIR)$(INCLUDEDIR)/cdatastructures

	@echo "Installing pkg-config file..."
	install -d $(DESTDIR)$(PKGCONFIGDIR)
	install -m 644 cdatastructures.pc $(DESTDIR)$(PKGCONFIGDIR)

uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/$(LIB_STATIC)
	rm -f $(DESTDIR)$(LIBDIR)/$(SHARED_LIB)
	rm -f $(DESTDIR)$(LIBDIR)/$(IMPORT_LIB)
	rm -rf $(DESTDIR)$(INCLUDEDIR)/cdatastructures
	rm -f $(DESTDIR)$(PKGCONFIGDIR)/cdatastructures.pc

# =========================
# Tests & cleanup
# =========================
test:
	$(MAKE) -C $(TEST_DIR)

clean:
	rm -f $(OBJECTS) $(LIB_STATIC) $(SHARED_LIB) $(IMPORT_LIB)

.PHONY: all install uninstall clean test
