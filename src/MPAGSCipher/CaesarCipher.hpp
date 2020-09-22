#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

// Standard library includes
#include <string>
#include <vector>

// Our project headers
#include "CipherMode.hpp"

/**
 * \file CaesarCipher.hpp
 * \brief Contains the declaration of the CaesarCipher class
 */

/**
 * \class CaesarCipher
 * \brief Encrypt or decrypt text using the Caesar cipher with the given key
 */
class CaesarCipher {
  public:
    /**
     * Create a new CaesarCipher with the given key
     *
     * \param key the key to use in the cipher
     */
    explicit CaesarCipher( const size_t key );

    /**
     * Create a new CaesarCipher, converting the given string into the key
     *
     * \param key the string to convert into the key to be used in the cipher
     */
    explicit CaesarCipher( const std::string& key );

    /**
     * Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    std::string applyCipher( const std::string& inputText, const CipherMode cipherMode ) const;

  private:
    /// The alphabet - used to determine the cipher character given the plain character and the key
    const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    /// The size of the alphabet
    const std::vector<char>::size_type alphabetSize_ = alphabet_.size();

    /// The cipher key, essentially a constant shift to be applied
    size_t key_ = 0;
};

#endif
