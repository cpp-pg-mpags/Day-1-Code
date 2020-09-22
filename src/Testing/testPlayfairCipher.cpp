//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "PlayfairCipher.hpp"

TEST_CASE("Playfair Cipher encryption", "[playfair]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( cc.applyCipher("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", CipherMode::Encrypt) == "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
}

TEST_CASE("Playfair Cipher decryption", "[playfair]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( cc.applyCipher("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", CipherMode::Decrypt) == "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ");
}
