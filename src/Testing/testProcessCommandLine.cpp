//! Unit Tests for MPAGSCipher processCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE("Help found correctly", "[commandline]") {

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "--help"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( res );
  REQUIRE( prog_set.helpRequested );
}

TEST_CASE("Version found correctly", "[commandline]") {

  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "--version"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( res );
  REQUIRE( prog_set.versionRequested );
}

TEST_CASE("Encrypt mode activated"){
  
  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "--encrypt"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( res );
  REQUIRE( prog_set.cipherMode == CipherMode::Encrypt  );
}

TEST_CASE("Decrypt mode activated"){
  
  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "--decrypt"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( res );
  REQUIRE( prog_set.cipherMode == CipherMode::Decrypt  );
}

TEST_CASE("Key entered with no key specified"){
  
  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-k"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( !res );
}

TEST_CASE("Key entered with key specified"){
  
  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-k", "4"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( res );
  REQUIRE( prog_set.cipherKey == "4");
}

TEST_CASE("Input file declared without using input file"){
  
  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-i"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( !res );
}

TEST_CASE("Input file declared"){
  
  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-i", "input.txt"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( res );
  REQUIRE( prog_set.inputFile == "input.txt");
}

TEST_CASE("Output file declared without specifying output file"){
  
  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-o"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( !res );
}

TEST_CASE("Output file declared"){
  
  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-o", "output.txt"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( res );
  REQUIRE( prog_set.outputFile == "output.txt");
}

TEST_CASE("Cipher type declared without specifying cipher"){
  
  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-c"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( !res );
}

TEST_CASE("Cipher type declared with unknown cipher"){
  
  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-c", "rubbish"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( !res );
}

TEST_CASE("Cipher type declared with Caesar cipher"){
  
  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-c", "caesar"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( res );
  REQUIRE( prog_set.cipherType == CipherType::Caesar);
}

TEST_CASE("Cipher type declared with Playfair cipher"){
  
  ProgramSettings prog_set{false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar};
  std::vector<std::string> cmd_line = {"mpags-cipher", "-c", "playfair"};
  bool res = processCommandLine(cmd_line, prog_set);

  REQUIRE( res );
  REQUIRE( prog_set.cipherType == CipherType::Playfair);
}
