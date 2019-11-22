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

// Need to wrap the construction in a lambda to use it in REQUIRE_THROWS_AS
auto makeCaesarCipherFromString = [](const std::string& key){CaesarCipher cc{key};};

TEST_CASE("Caesar Cipher negative key", "[caesar]") {
  REQUIRE_THROWS_AS( makeCaesarCipherFromString("-1"), InvalidKey);
}

TEST_CASE("Caesar Cipher non-numeric key", "[caesar]") {
  REQUIRE_THROWS_AS( makeCaesarCipherFromString("hello"), InvalidKey);
}

TEST_CASE("Caesar Cipher too large a key", "[caesar]") {
  REQUIRE_THROWS_AS( makeCaesarCipherFromString("999999999999999999999"), InvalidKey);
}
