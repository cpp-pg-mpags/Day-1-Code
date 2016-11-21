
// Standard Library includes
#include <iostream>
#include <memory>
#include <string>

// Our project headers
#include "CipherFactory.hpp"
#include "Cipher.hpp"
#include "CipherType.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

std::unique_ptr<Cipher> cipherFactory(const CipherType type, const std::string& key)
{
  switch ( type ) {

    case CipherType::Caesar:
      {
	// We have the key as a string, but the Caesar cipher needs an unsigned long, so we first need to convert it
	// We default to having a key of 0, i.e. no encryption, if no key was provided on the command line
	size_t caesarKey {0};

	if ( ! key.empty() ) {
	  // The conversion function will throw an exception if the string does
	  // not represent a valid unsigned long integer
	  try {

	    caesarKey = std::stoul(key);

	  } catch ( const std::invalid_argument& ) {

	    std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
	              << "        the supplied key (" << key << ") could not be successfully converted" << std::endl;
	    return std::unique_ptr<Cipher>();

	  } catch ( const std::out_of_range& ) {

	    std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
	              << "        the supplied key (" << key << ") was not in the right range" << std::endl;
	    return std::unique_ptr<Cipher>();

	  }
	}

	return std::make_unique<CaesarCipher>( caesarKey );
      }

    case CipherType::Playfair:
      {
	return std::make_unique<PlayfairCipher>( key );
      }

    case CipherType::Vigenere:
      {
	return std::make_unique<VigenereCipher>( key );
      }
  }

  // Just in case we drop out of the switch (shouldn't be possible but gcc seems to think it is)
  return std::unique_ptr<Cipher>();
}

