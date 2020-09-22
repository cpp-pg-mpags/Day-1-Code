//! Unit Tests for MPAGSCipher processCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE("Help found correctly", "[commandline]") {

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "--help"};
  REQUIRE_NOTHROW(processCommandLine(cmd_line, prog_set));
  REQUIRE( prog_set.helpRequested );
}

TEST_CASE("Version found correctly", "[commandline]") {

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "--version"};
  REQUIRE_NOTHROW(processCommandLine(cmd_line, prog_set));
  REQUIRE( prog_set.versionRequested );
}

TEST_CASE("Encrypt mode activated"){

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "--encrypt"};
  REQUIRE_NOTHROW(processCommandLine(cmd_line, prog_set));
  REQUIRE( prog_set.cipherMode == CipherMode::Encrypt  );
}

TEST_CASE("Decrypt mode activated"){

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "--decrypt"};
  REQUIRE_NOTHROW(processCommandLine(cmd_line, prog_set));
  REQUIRE( prog_set.cipherMode == CipherMode::Decrypt  );
}

TEST_CASE("Key entered with no key specified"){

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-k"};
  REQUIRE_THROWS_AS(processCommandLine(cmd_line, prog_set), MissingArgument);
}

TEST_CASE("Key entered with key specified"){

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-k", "4"};
  REQUIRE_NOTHROW(processCommandLine(cmd_line, prog_set));
  REQUIRE( prog_set.cipherKey == "4");
}

TEST_CASE("Input file declared without using input file"){

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-i"};
  REQUIRE_THROWS_AS(processCommandLine(cmd_line, prog_set), MissingArgument);
}

TEST_CASE("Input file declared"){

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-i", "input.txt"};
  REQUIRE_NOTHROW( processCommandLine(cmd_line, prog_set));
  REQUIRE( prog_set.inputFile == "input.txt");
}

TEST_CASE("Output file declared without specifying output file"){

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-o"};
  REQUIRE_THROWS_AS(processCommandLine(cmd_line, prog_set), MissingArgument);
}

TEST_CASE("Output file declared"){

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-o", "output.txt"};
  REQUIRE_NOTHROW( processCommandLine(cmd_line, prog_set));
  REQUIRE( prog_set.outputFile == "output.txt");
}

TEST_CASE("Cipher type declared without specifying cipher"){

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-c"};
  REQUIRE_THROWS_AS( processCommandLine(cmd_line, prog_set), MissingArgument);
}

TEST_CASE("Cipher type declared with unknown cipher"){

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-c", "rubbish"};
  REQUIRE_THROWS_AS( processCommandLine(cmd_line, prog_set), UnknownArgument);
}

TEST_CASE("Cipher type declared with Caesar cipher"){

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-c", "caesar"};
  REQUIRE_NOTHROW( processCommandLine(cmd_line, prog_set));
  REQUIRE( prog_set.cipherType == CipherType::Caesar);
}

TEST_CASE("Cipher type declared with Playfair cipher"){

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-c", "playfair"};
  REQUIRE_NOTHROW( processCommandLine(cmd_line, prog_set));
  REQUIRE( prog_set.cipherType == CipherType::Playfair);
}

TEST_CASE("Cipher type declared with Vigenere cipher"){

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-c", "vigenere"};
  REQUIRE_NOTHROW( processCommandLine(cmd_line, prog_set));
  REQUIRE( prog_set.cipherType == CipherType::Vigenere);
}
