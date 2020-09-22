// Standard Library includes
#include <iostream>

// Our project headers
#include "ProcessCommandLine.hpp"

bool processCommandLine(const std::vector<std::string>& args,
                        ProgramSettings& settings)
{
  // Status flag to indicate whether or not the parsing was successful
  bool processStatus(true);

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
        std::cerr << "[error] -i/--infile requires a filename argument" << std::endl;
        // Set the flag to indicate the error and terminate the loop
        processStatus = false;
        break;
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
        std::cerr << "[error] -o/--outfile requires a filename argument" << std::endl;
        // Set the flag to indicate the error and terminate the loop
        processStatus = false;
        break;
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
        std::cerr << "[error] -k/--key requires a string argument" << std::endl;
        // Set the flag to indicate the error and terminate the loop
        processStatus = false;
        break;
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
        std::cerr << "[error] -c requires a string argument" << std::endl;
        // Set the flag to indicate the error and terminate the loop
        processStatus = false;
        break;
      }
      else {
        // Got the key, so assign the value and advance past it
	if ( args[i+1] == "caesar" ) {
	  settings.cipherType = CipherType::Caesar;
	} else if ( args[i+1] == "playfair" ) {
	  settings.cipherType = CipherType::Playfair;
	} else {
	  std::cerr << "[error] unknown cipher '" << args[i+1] << "'\n";
	  processStatus = false;
	  break;
	}
        ++i;
      }
    }
    else {
      // Have encoutered an unknown flag, output an error message, set the flag
      // to indicate the error and terminate the loop
      std::cerr << "[error] unknown argument '" << args[i] << "'\n";
      processStatus = false;
      break;
    }
  }

  return processStatus;
}
