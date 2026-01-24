# =========================
# Project configuration
# =========================
LIB_NAME    := cdatastructures

# --- Platform Detection ---
UNAME_S     := $(shell uname -s)

# Default to Linux/Unix behavior
PLATFORM    := linux
SHARED_EXT  := so
PREFIX      ?= /usr/local

# Detect Windows (MinGW/MSYS)
ifneq (,$(findstring MINGW,$(UNAME_S)))
    PLATFORM := windows
    SHARED_EXT := dll
    # Windows standard install paths are often different, but we keep your defaults
endif

# Detect MacOS
ifeq ($(UNAME_S),Darwin)
    PLATFORM := macos
    SHARED_EXT := dylib
endif

# --- Artifact Names ---
LIB_STATIC  := lib$(LIB_NAME).a

ifeq ($(PLATFORM),windows)
    SHARED_LIB := $(LIB_NAME).$(SHARED_EXT)
    SHARED_LDFLAGS := -shared
else
    SHARED_LIB := lib$(LIB_NAME).$(SHARED_EXT)
    SHARED_LDFLAGS := -shared
endif


# --- Toolchain ---
CC          ?= gcc
AR          ?= ar
CFLAGS      := -Wall -Wextra -Wpedantic -std=c11 -O2
# -fPIC is required for shared libraries on Linux/Mac
CFLAGS      += -fPIC

INCLUDEDIR  := $(PREFIX)/include
LIBDIR      := $(PREFIX)/lib
PKGCONFIGDIR:= $(LIBDIR)/pkgconfig

SRC_DIR     := src
INC_DIR     := include
TEST_DIR    := tests


# =========================
# Source discovery
# =========================
# Option 1: Using shell find to exclude files ending in _ll.c
SOURCES := $(shell find $(SRC_DIR) -name "*.c" ! -name "*_ll.c")

# Option 2: If you prefer to find all and then filter in Makefile logic
# ALL_SOURCES := $(shell find $(SRC_DIR) -name "*.c")
# SOURCES     := $(filter-out %_ll.c, $(ALL_SOURCES))


OBJECTS := $(SOURCES:.c=.o)


# =========================
# Build rules
# =========================
all: $(LIB_STATIC) $(SHARED_LIB)

$(LIB_STATIC): $(OBJECTS)
	$(AR) rcs $@ $^

$(SHARED_LIB): $(OBJECTS)
	$(CC) $(SHARED_LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@


# =========================
# Install / uninstall
# =========================
install: all
	@echo "Installing libraries..."
	install -d $(DESTDIR)$(LIBDIR)
	install -m 644 $(LIB_STATIC) $(DESTDIR)$(LIBDIR)
	# FIX: Use the variable directly; 755 is correct for .so/.dll (executable)
	install -m 755 $(SHARED_LIB) $(DESTDIR)$(LIBDIR)

	@echo "Installing headers..."
	# FIX: Restored header installation
	install -d $(DESTDIR)$(INCLUDEDIR)/cdatastructures
	install -m 644 $(INC_DIR)/*.h $(DESTDIR)$(INCLUDEDIR)/cdatastructures

	@echo "Installing pkg-config file..."
	install -d $(DESTDIR)$(PKGCONFIGDIR)
	install -m 644 cdatastructures.pc $(DESTDIR)$(PKGCONFIGDIR)

uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/$(LIB_STATIC)
	rm -f $(DESTDIR)$(LIBDIR)/$(SHARED_LIB)
	rm -rf $(DESTDIR)$(INCLUDEDIR)/cdatastructures
	rm -f $(DESTDIR)$(PKGCONFIGDIR)/cdatastructures.pc

# =========================
# Tests & cleanup
# =========================
test:
	$(MAKE) -C $(TEST_DIR)

clean:
	rm -f $(OBJECTS) $(LIB_STATIC) $(SHARED_LIB)

.PHONY: all install uninstall clean test