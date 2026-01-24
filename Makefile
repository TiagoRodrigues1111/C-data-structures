# =========================
# Project configuration
# =========================
LIB_NAME    := cdatastructures
LIB_STATIC  := lib$(LIB_NAME).a

CC          := gcc
AR          := ar
CFLAGS      := -Wall -Wextra -Wpedantic -std=c11 -O2

PREFIX      ?= /usr/local
INCLUDEDIR  := $(PREFIX)/include
LIBDIR      := $(PREFIX)/lib
PKGCONFIGDIR:= $(LIBDIR)/pkgconfig

SRC_DIR     := src
INC_DIR     := include
TEST_DIR    := tests

# =========================
# Source discovery
# =========================
SOURCES := $(shell find $(SRC_DIR) -name "*.c")
OBJECTS := $(SOURCES:.c=.o)

# =========================
# Build rules
# =========================
all: $(LIB_STATIC)

$(LIB_STATIC): $(OBJECTS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# =========================
# Install / uninstall
# =========================
install: $(LIB_STATIC)
	@echo "Installing library..."
	install -d $(DESTDIR)$(LIBDIR)
	install -m 644 $(LIB_STATIC) $(DESTDIR)$(LIBDIR)

	@echo "Installing headers..."
	install -d $(DESTDIR)$(INCLUDEDIR)/cdatastructures
	install -m 644 $(INC_DIR)/*.h $(DESTDIR)$(INCLUDEDIR)/cdatastructures

	@echo "Installing pkg-config file..."
	install -d $(DESTDIR)$(PKGCONFIGDIR)
	install -m 644 cdatastructures.pc $(DESTDIR)$(PKGCONFIGDIR)

uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/$(LIB_STATIC)
	rm -rf $(DESTDIR)$(INCLUDEDIR)/cdatastructures
	rm -f $(DESTDIR)$(PKGCONFIGDIR)/cdatastructures.pc

# =========================
# Tests & cleanup
# =========================
test:
	$(MAKE) -C $(TEST_DIR)

clean:
	rm -f $(OBJECTS) $(LIB_STATIC)

.PHONY: all install uninstall clean test
