//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

TEST_CASE("Vigenere Cipher encryption", "[vigenere]") {
  VigenereCipher cc{"hello"};
  REQUIRE( cc.applyCipher("THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES", CipherMode::Encrypt) == "ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ");
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]") {
  VigenereCipher cc{"hello"};
  REQUIRE( cc.applyCipher("ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ", CipherMode::Decrypt) == "THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES");
}

// Need to wrap the construction in a lambda to use it in REQUIRE_THROWS_AS
auto makeVigenereCipher = [](const std::string& key){VigenereCipher cc{key};};

TEST_CASE("Vigenere Cipher empty key", "[vigenere]") {
  REQUIRE_THROWS_AS( makeVigenereCipher(""),  InvalidKey);
  REQUIRE_THROWS_AS( makeVigenereCipher("!"), InvalidKey);
  REQUIRE_THROWS_AS( makeVigenereCipher("1"), InvalidKey);
}
