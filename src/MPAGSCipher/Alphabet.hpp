#ifndef MPAGSCIPHER_ALPHABET_HPP
#define MPAGSCIPHER_ALPHABET_HPP

/**
 * \file Alphabet.hpp
 * \brief Contains the declaration of the Alphabet namespace, which holds various commonly used constants
 */

/**
 * \namespace Alphabet
 * \brief Namespace to hold alphabet-related constants
 */
namespace Alphabet {
  /// The alphabet
  const std::string alphabet {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

  /// The type that represents the size of the alphabet
  using AlphabetSize = std::string::size_type;

  /// The size of the alphabet
  const AlphabetSize size { alphabet.size() };
}

#endif // MPAGSCIPHER_ALPHABET_HPP 
