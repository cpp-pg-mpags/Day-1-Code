
// Standard library includes
#include <iostream>
#include <string>
#include <algorithm>

// Out project headers
#include "Alphabet.hpp"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"

VigenereCipher::VigenereCipher( const std::string& key )
{
  this->setKey( key );
}

void VigenereCipher::setKey( const std::string& key )
{
  // Store the key
  key_ = key;

  // Make sure the key is upper case
  std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );

  // Remove non-alphabet characters
  key_.erase( std::remove_if( std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); } ),
		  std::end(key_) );

  // Check that the key is not now empty
  if ( key_.empty() ) {
    // If it is we would ideally throw an exception to indicate a problem (see Day 6)
    // For now we'll just set it to be some default value and print a warning
    key_ = "VIGENEREEXAMPLE";
    std::cerr << "[warning] key provide to VigenereCipher is empty, setting it to the default: " << key_ << std::endl;
  }

  // Loop through the key
  charLookup_.clear();
  for ( const char letter : key_ ) {

    // Check if we've already seen this letter before
    if ( charLookup_.find( letter ) != charLookup_.end() ) {
      continue;
    }

    // Find the position of the letter in the alphabet
    std::string::size_type index = Alphabet::alphabet.find( letter );

    // Construct a Caesar cipher object in-place using the position as the key,
    // storing it so that it can be retrieved based on the character in the key
    charLookup_.emplace( std::piecewise_construct, std::make_tuple(letter), std::make_tuple(index) );
  }

}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode ) const
{
  // Create the output string
  std::string outputText {""};

  // Loop through the text
  for ( std::string::size_type i {0}; i < inputText.size(); ++i ) {

    // Determine the corresponding character in the key based on the position
    // (repeating the key if necessary)
    char keyChar = key_[ i % key_.size() ];

    // Find the corresponding Caesar cipher
    auto iter = charLookup_.find( keyChar );

    // Use it to encrypt/decrypt the character of the text
    std::string oldChar { inputText[i] };
    std::string newChar { iter->second.applyCipher( oldChar, cipherMode ) };

    // Put the new character into the output
    outputText += newChar;
  }

  // Return the output text
  return outputText;
}

