#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

// Standard library includes
#include <string>
#include <map>

// Our project headers
#include "CipherMode.hpp"

/**
 * \file PlayfairCipher.hpp
 * \brief Contains the declaration of the PlayfairCipher class
 */

/**
 * \class PlayfairCipher
 * \brief Encrypt or decrypt text using the Playfair cipher with the given key
 */
class PlayfairCipher {
  public:
    /**
     * Create a new PlayfairCipher with the given key
     *
     * \param key the key to use in the cipher
     */
    explicit PlayfairCipher( const std::string& key );

    /**
     * Set the key to be used for the encryption/decryption
     *
     * \param key the key to use in the cipher
     */
    void setKey( const std::string& key );

    /**
     * Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    std::string applyCipher( const std::string& inputText, const CipherMode cipherMode ) const;

  private:
    /// The grid dimension
    const std::string::size_type gridDim_ = 5;

    /// The key length = grid dim^2
    const std::string::size_type keyLength_ = gridDim_*gridDim_;

    /// The cipher key
    std::string key_ = "";

    // Lookup tables generated from the key

    /// Type definition for the coordinates in the 5x5 table
    using PlayfairCoords = std::pair<std::string::size_type,std::string::size_type>;

    /// Lookup table to go from the character to the coordinates
    std::map<char,PlayfairCoords> charLookup_;

    /// Lookup table to go from the coordinates to the character
    std::map<PlayfairCoords,char> coordLookup_;
};

#endif
