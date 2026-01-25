# C-data-structures

This is a repository containing declarations and definitions of different data structures in C. Multiple definitions are proposed for each data structure, such as alternatives using arrays and/or linked lists. It is designed for learning, practice, and use in larger projects. Each data structure is implemented with comments and example usage.

---

### TODO

  Documents are not updated

---

The library is designed to be:
- Generic (void-pointer based, user-defined element size)
- Portable across Linux, macOS, WSL, and Windows (via MSYS2)
- Usable with static or shared linking
- Friendly to pkg-config
---

## Features

- Stack (array-based and linked-list–based)
- Queue (array-based and linked-list–based)
- Priority Queue (binary heap)
- Opaque data structures (implementation hidden from users)
- Custom comparator support
- Static and shared library builds

---

## Requirements

- C compiler (gcc or compatible)
- make
- pkg-config
- POSIX-like environment:
  - Linux / BSD
  - macOS
  - Windows via MSYS2 (MinGW64) or WSL

---

## Build

Clone the repository and build the library:


    git clone https://github.com/TiagoRodrigues1111/C-data-structures.git
    cd cdatastructures
    make

This will generate:

- Static library: libcdatastructures.a
- Shared library:
  - Linux: libcdatastructures.so
  - macOS: libcdatastructures.dylib
  - Windows (MSYS2): cdatastructures.dll and libcdatastructures.dll.a

---

## Install

### System-wide install

#### Linux / macOS / WSL

    sudo make install

Installs to:
- Headers: /usr/local/include/cdatastructures
- Libraries: /usr/local/lib
- pkg-config file: /usr/local/lib/pkgconfig/cdatastructures.pc

#### Windows (MSYS2 MinGW64)

From the MinGW64 shell:

    make install

Installs to:
- Headers: /mingw64/include/cdatastructures
- Libraries: /mingw64/lib
- pkg-config file: /mingw64/lib/pkgconfig/cdatastructures.pc

---

### Custom install prefix (recommended)

You can install the library into a custom directory:

    make install PREFIX=/path/to/install

Example:

    make install PREFIX=$HOME/.local

This installs to:
- $PREFIX/include/cdatastructures
- $PREFIX/lib
- $PREFIX/lib/pkgconfig

---

## Using the Library

### Using pkg-config (recommended)

    gcc main.c $(pkg-config --cflags --libs cdatastructures)

### Manual include and link

    gcc main.c -I/usr/local/include -L/usr/local/lib -lcdatastructures

Adjust include and library paths if you used a custom prefix.

---

## Runtime Shared Library Path

### Linux / WSL

If the shared library is installed into a non-standard directory (for example /usr/local/lib or a custom prefix):

    export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

For a permanent system-wide solution:

    sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/cdatastructures.conf'
    sudo ldconfig

### Windows (MSYS2)

Ensure the directory containing cdatastructures.dll is in your PATH at runtime.

---

## Uninstall

    sudo make uninstall

Or for a custom prefix:

    make uninstall PREFIX=/path/to/install

---

## Notes

- All data structures are opaque: users interact only through the public API.
- Element size and comparison logic are provided by the user.
- The API avoids C99-only features when possible to maintain broad compatibility.

---

## License

MIT License (or update this section with your chosen license).
