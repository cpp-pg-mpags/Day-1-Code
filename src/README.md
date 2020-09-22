# mpags-cipher
A simple command line tool for encrypting/decrypting text using classical ciphers

# Building `mpags-cipher`
Compilation of `mpags-cipher` requires the [CMake](http://www.cmake.org)
build tool, plus a  C++11 compatible compiler (GCC 4.8 or better, Clang
3.4 or better are recommended) and `make` on a UNIX operating system.
Windows platforms with Visual Studio 2015 or better are also expected to
work, but not tested.

To build from a clone of this repository, open a terminal window
and change directory into the build directory:

```
$ ls
README.md        build            src
$ cd build
```

Run `cmake` in this directory, pointing it to the directory holding the top
level CMake script for the project:

```
$ cmake ../src
... system specific output ...
-- Configuring done
-- Generating done
-- Build files have been written to: ... your build dir path ...
$
```

The exact output will depend on your system, compiler and build directory
location, but you should not see any errors. CMake will generate
Makefiles by default on UNIX platforms, so to build, simply run `make`
in the build directory:

```
$ ls
CMakeCache.txt      CMakeFiles          Makefile            cmake_install.cmake
$ make
... verbose output ...
[100%] Built target mpags-cipher
...
$
```

Again, the exact output will be system specific, but you should see the
`mpags-cipher` target built without error. The resulting `mpags-cipher`
executable can then be run directly, and provides the following command
line options:

```
$ ./mpags-cipher --help
Usage: mpags-cipher [-i <file>] [-o <file>] [-k <key>] [--encrypt/--decrypt]

Encrypts/Decrypts input alphanumeric text using classical ciphers

Available options:

  -h|--help        Print this help message and exit

  --version        Print version information

  -i FILE          Read text to be processed from FILE
                   Stdin will be used if not supplied

  -o FILE          Write processed text to FILE
                   Stdout will be used if not supplied

  -k KEY           Specify the cipher KEY
                   A null key, i.e. no encryption, is used if not supplied

  --encrypt        Will use the cipher to encrypt the input text (default behaviour)

  --decrypt        Will use the cipher to decrypt the input text
```

If no input file is supplied, `mpags-cipher` will wait for user input
from the keyboard until RETURN followed by CTRL-D are pressed.
It will then echo the input to stdout or write it to the file supplied with
the `-o` option.

To ensure the input text can be used with the character sets known to
classical ciphers, it is transliterated using the following rules:

- Alphabetical characters are converted to uppercase
- Digits are translated to their English equivalent words (e.g. '0' -> "ZERO")
- All other characters (punctuation) are discarded

At present only the Caesar Cipher is supported.

# Source Code Layout
Under this directory, the code and associated files are organised as
follows:

```
.
├── README.md                          Top-level README, describes layout of the repository
├── build
└── src
    ├── CMakeLists.txt                 CMake build script
    ├── Documentation                  Subdirectory for documentation of the MPAGSCipher library
    │   ├── CMakeLists.txt
    │   └── Doxyfile.in
    ├── LICENSE                        License file, in our case MIT
    ├── MPAGSCipher                    Subdirectory for MPAGSCipher library code
    │   ├── CMakeLists.txt
    │   ├── CaesarCipher.cpp
    │   ├── CaesarCipher.hpp
    │   ├── CipherMode.hpp
    │   ├── CipherType.hpp
    │   ├── ProcessCommandLine.cpp
    │   ├── ProcessCommandLine.hpp
    │   ├── TransformChar.cpp
    │   └── TransformChar.hpp
    ├── README.md                      This file, describes the project
    ├── Testing                        Subdirectory for testing the MPAGSCipher library
    │   ├── CMakeLists.txt
    │   ├── catch.hpp
    │   ├── testCaesarCipher.cpp
    │   ├── testCatch.cpp
    │   ├── testHello.cpp
    │   ├── testProcessCommandLine.cpp
    │   └── testTransformChar.cpp
    └── mpags-cipher.cpp               Main program C++ source file
```

# Copying
`mpags-cipher` is licensed under the terms of the MIT License. Please see
the file [`LICENSE`](LICENSE) for full details.
