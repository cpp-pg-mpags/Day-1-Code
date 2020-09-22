#ifndef MPAGSCIPHER_TRANSFORMCHAR_HPP
#define MPAGSCIPHER_TRANSFORMCHAR_HPP

#include <string>

/**
 * \file TransformChar.hpp
 * \brief Contains the declaration of the function for processing the input text
 */

/**
 * \brief Transliterate char to string
 *
 * Alphabet characters are made uppercase
 * Digits are replaced with their english word equivalents
 * All other characters are discarded
 *
 * \param in the character to process
 * \return the transliterated string
 */
std::string transformChar(const char in);

#endif // MPAGSCIPHER_TRANSFORMCHAR_HPP
