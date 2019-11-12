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

TEST_CASE("Vigenere Cipher empty key", "[vigenere]") {
  REQUIRE_THROWS_AS([](){VigenereCipher vc{""};}(), InvalidKey);
  REQUIRE_THROWS_AS([](){VigenereCipher vc{"!"};}(), InvalidKey);
  REQUIRE_THROWS_AS([](){VigenereCipher vc{"1"};}(), InvalidKey);
}
