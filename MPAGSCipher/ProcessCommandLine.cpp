// Standard Library includes
#include <string>

// Our project headers
#include "ProcessCommandLine.hpp"

void processCommandLine(const std::vector<std::string>& args,
                        ProgramSettings& settings)
{
  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type nArgs {args.size()};

  // Process the arguments - ignore zeroth element, as we know this to be the
  // program name and don't need to worry about it
  for (size_type i {1}; i < nArgs; ++i) {

    if (args[i] == "-h" || args[i] == "--help") {
      // Set the indicator and terminate the loop
      settings.helpRequested = true;
      break;
    }
    else if (args[i] == "--version") {
      // Set the indicator and terminate the loop
      settings.versionRequested = true;
      break;
    }
    else if ( args[i] == "-i" || args[i] == "--infile" ) {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nArgs-1) {
        // Throw an exception to indicate the missing argument
        throw MissingArgument("-i/--infile requires a filename argument");
      }
      else {
        // Got filename, so assign value and advance past it
        settings.inputFile = args[i+1];
        ++i;
      }
    }
    else if ( args[i] == "-o" || args[i] == "--outfile" ) {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nArgs-1) {
        // Throw an exception to indicate the missing argument
        throw MissingArgument("-o/--outfile requires a filename argument");
      }
      else {
        // Got filename, so assign value and advance past it
        settings.outputFile = args[i+1];
        ++i;
      }
    }
    else if ( args[i] == "-k" || args[i] == "--key" ) {
      // Handle cipher key option
      // Next element is the key unless -k is the last argument
      if (i == nArgs-1) {
        // Throw an exception to indicate the missing argument
        throw MissingArgument("-k/--key requires a string argument");
      }
      else {
        // Got the key, so assign the value and advance past it
        settings.cipherKey = args[i+1];
        ++i;
      }
    }
    else if ( args[i] == "--encrypt" ) {
      // Handle encrypt option
      settings.cipherMode = CipherMode::Encrypt;
    }
    else if ( args[i] == "--decrypt" ) {
      // Handle decrypt option
      settings.cipherMode = CipherMode::Decrypt;
    }
    else if ( args[i] == "-c" || args[i] == "--cipher" ) {
      // Handle cipher type option
      // Next element is the name of the cipher, unless -c is the last argument
      if (i == nArgs-1) {
        // Throw an exception to indicate the missing argument
        throw MissingArgument("-c/--cipher requires a string argument");
      }
      else {
        // Got the key, so assign the value and advance past it
        if ( args[i+1] == "caesar" ) {
          settings.cipherType = CipherType::Caesar;
        } else if ( args[i+1] == "playfair" ) {
          settings.cipherType = CipherType::Playfair;
        } else if ( args[i+1] == "vigenere" ) {
          settings.cipherType = CipherType::Vigenere;
        } else {
          throw UnknownArgument("unknown cipher '" + args[i+1] + "'");
        }
        ++i;
      }
    }
    else {
      // Have encoutered an unknown argument, so thrown the corresponding exception
      throw UnknownArgument("unknown argument '" + args[i] + "'");
    }
  }

}
