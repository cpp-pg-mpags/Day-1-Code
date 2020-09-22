// Standard Library includes
#include <iostream>

// Our project headers
#include "ProcessCommandLine.hpp"

bool processCommandLine(const std::vector<std::string>& args,
                        bool& helpRequested,
                        bool& versionRequested,
                        std::string& inputFile,
                        std::string& outputFile,
                        std::string& cipher_key,
                        bool& encrypt)
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
      helpRequested = true;
      break;
    }
    else if (args[i] == "--version") {
      // Set the indicator and terminate the loop
      versionRequested = true;
      break;
    }
    else if (args[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nArgs-1) {
        std::cerr << "[error] -i requires a filename argument" << std::endl;
        // Set the flag to indicate the error and terminate the loop
        processStatus = false;
        break;
      }
      else {
        // Got filename, so assign value and advance past it
        inputFile = args[i+1];
        ++i;
      }
    }
    else if (args[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nArgs-1) {
        std::cerr << "[error] -o requires a filename argument" << std::endl;
        // Set the flag to indicate the error and terminate the loop
        processStatus = false;
        break;
      }
      else {
        // Got filename, so assign value and advance past it
        outputFile = args[i+1];
        ++i;
      }
    }
    else if (args[i] == "-k") {
      // Handle cipher key option
      // Next element is the key unless -k is the last argument
      if (i == nArgs-1) {
        std::cerr << "[error] -k requires a positive integer argument" << std::endl;
        // Set the flag to indicate the error and terminate the loop
        processStatus = false;
        break;
      }
      else {
        // Got the key, so assign the value and advance past it
        cipher_key = args[i+1];
        ++i;
      }
    }
    else if ( args[i] == "--encrypt" ) {
            encrypt = true;
    }
    else if ( args[i] == "--decrypt" ) {
            encrypt = false;
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
