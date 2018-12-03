//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"

TEST_CASE("Caesar Cipher encryption", "[caesar]") {
  CaesarCipher cc{10};
  REQUIRE( cc.applyCipher("HELLOWORLD", CipherMode::Encrypt) == "ROVVYGYBVN");
}

TEST_CASE("Caesar Cipher decryption", "[caesar]") {
  CaesarCipher cc{10};
  REQUIRE( cc.applyCipher("ROVVYGYBVN", CipherMode::Decrypt) == "HELLOWORLD");
}

TEST_CASE("Caesar Cipher negative key", "[caesar]") {
  REQUIRE_THROWS_AS(CaesarCipher cc{"-1"}, InvalidKey);
}

TEST_CASE("Caesar Cipher non-numeric key", "[caesar]") {
  REQUIRE_THROWS_AS(CaesarCipher cc{"hello"}, InvalidKey);
}

TEST_CASE("Caesar Cipher too large a key", "[caesar]") {
  REQUIRE_THROWS_AS(CaesarCipher cc{"999999999999999999999"}, InvalidKey);
}
