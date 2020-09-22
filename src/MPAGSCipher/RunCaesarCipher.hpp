#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

#include <string>

//! Encrypt or decrypt text using the Caesar cipher with the given key
std::string runCaesarCipher( const std::string& inputText, const size_t key, const bool encrypt );

#endif
