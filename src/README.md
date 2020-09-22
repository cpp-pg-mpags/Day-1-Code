# mpags-cipher
A simple command line tool for encrypting/decrypting text using classical ciphers

# Building `mpags-cipher`
Compilation of `mpags-cipher` requires a  C++11 compatible compiler
(GCC 4.8 or better, Clang 3.4 or better are recommended) and `make`
on a UNIX operating system.
Windows platforms with Visual Studio 2015 or better are also expected to
work, but not tested.

To build from a clone of this repository, open a terminal window
and change directory into that holding this README. Then run:
```
$ ls
LICENSE          README.md        mpags-cipher.cpp
$ g++ -std=c++11 -Wall -Wextra -Werror -Wfatal-errors -pedantic -Wshadow -o mpags-cipher mpags-cipher.cpp
$ ./mpags-cipher
```

If no input file is supplied, `mpags-cipher` will wait for user input
from the keyboard until RETURN followed by CTRL-D are pressed.
To ensure the input text can be used with the character sets known to
classical ciphers, it is transliterated using the following rules:

- Alphabetical characters are converted to uppercase
- Digits are translated to their English equivalent words (e.g. '0' -> "ZERO")
- All other characters (punctuation) are discarded

The results of this transliteration are output after CTRL-D.


# Source Code Layout
Under this directory, the code and associated files are organised as
follows:

```
$ tree
.
├── README.md               Top-level README, describes layout of the repository
├── build
└── src
    ├── LICENSE             License file, in our case MIT
    ├── README.md           This file, describes the project
    └── mpags-cipher.cpp    Main program C++ source file
```

# Copying
`mpags-cipher` is licensed under the terms of the MIT License. Please see
the file [`LICENSE`](LICENSE) for full details.
