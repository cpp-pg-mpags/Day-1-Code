
// Standard Library includes
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
      return std::make_unique<CaesarCipher>( key );

    case CipherType::Playfair:
      return std::make_unique<PlayfairCipher>( key );

    case CipherType::Vigenere:
      return std::make_unique<VigenereCipher>( key );
  }

  // Just in case we drop out of the switch (shouldn't be possible but gcc seems to think it is)
  return std::unique_ptr<Cipher>();
}

