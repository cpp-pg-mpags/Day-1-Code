// Standard Library includes
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Our project headers
#include "CipherFactory.hpp"
#include "CipherMode.hpp"
#include "CipherType.hpp"
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
  
// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  ProgramSettings settings { false, false, "", "", "", CipherMode::Encrypt, CipherType::Caesar };

  // Process command line arguments
  try {

    processCommandLine(cmdLineArgs, settings);

  } catch ( const MissingArgument& e ) {

    std::cerr << "[error] Missing argument: " << e.what() << std::endl;
    return 1;

  } catch ( const UnknownArgument& e ) {

    std::cerr << "[error] Unknown argument: " << e.what() << std::endl;
    return 1;

  }

  // Handle help, if requested
  if (settings.helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i/--infile <file>] [-o/--outfile <file>] [-c/--cipher <cipher>] [-k/--key <key>] [--encrypt/--decrypt]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help\n"
      << "                      Print this help message and exit\n\n"
      << "  -v|--version\n"
      << "                      Print version information\n\n"
      << "  -i|--infile FILE\n"
      << "                      Read text to be processed from FILE\n"
      << "                      Stdin will be used if not supplied\n\n"
      << "  -o|--outfile FILE\n"
      << "                      Write processed text to FILE\n"
      << "                      Stdout will be used if not supplied\n\n"
      << "  -c|--cipher CIPHER\n"
      << "                      Specify the cipher to be used to perform the encryption/decryption\n"
      << "                      CIPHER can be caesar, playfair or vigenere - caesar is the default\n\n"
      << "  -k|--key KEY\n"
      << "                      Specify the cipher KEY\n"
      << "                      A null key, i.e. no encryption, is used if not supplied\n\n"
      << "  --encrypt\n"
      << "                      Will use the cipher to encrypt the input text (default behaviour)\n\n"
      << "  --decrypt\n"
      << "                      Will use the cipher to decrypt the input text\n\n";
    // Help requires no further action, so return from main,
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  if (settings.versionRequested) {
    std::cout << "0.5.0" << std::endl;
    // Like help, requires no further action, so return from main,
    // with 0 used to indicate success
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  if (!settings.inputFile.empty()) {

    // Open the file and check that we can read from it
    std::ifstream inputStream(settings.inputFile);
    if (!inputStream.good()) {
      std::cerr << "[error] failed to create istream on file '" << settings.inputFile << "'" << std::endl;
      return 1;
    }

    // Loop over each character from the file
    while(inputStream >> inputChar)
    {
      inputText += transformChar(inputChar);
    }

  } else {

    // Loop over each character from user input
    // (until Return then CTRL-D (EOF) pressed)
    while(std::cin >> inputChar)
    {
      inputText += transformChar(inputChar);
    }
  }

  // Request construction of the appropriate cipher
  std::unique_ptr<Cipher> cipher;
  try {
    cipher = cipherFactory( settings.cipherType, settings.cipherKey );
  } catch ( const InvalidKey& e ) {
    std::cerr << "[error] Invalid key: " << e.what() << std::endl;
    return 1;
  }

  // Check that the cipher was constructed successfully
  if ( ! cipher ) {
    std::cerr << "[error] problem constructing requested cipher" << std::endl;
    return 1;
  }

  // Run the cipher on the input text, specifying whether to encrypt/decrypt
  std::string outputText { cipher->applyCipher( inputText, settings.cipherMode ) };

  // Output the transliterated text
  if (!settings.outputFile.empty()) {

    // Open the file and check that we can write to it
    std::ofstream outputStream(settings.outputFile);
    if (!outputStream.good()) {
      std::cerr << "[error] failed to create ostream on file '" << settings.outputFile << "'" << std::endl;
      return 1;
    }

    // Print the transliterated text to the file
    outputStream << outputText << std::endl;

  } else {

    // Print the transliterated text to the screen
    std::cout << outputText << std::endl;
  }

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
