# - CMake buildscript for Documentation subdirectory

# - Doxygen documentation
# Find an install of Doxygen (we're not too fussy about the version) using CMake's find_package command
find_package(Doxygen REQUIRED)

# Configure+Copy Doxygen template file from current source dir to current binary dir
# '@ONLY' means replace any instances of '@VARIABLE@' in the input file with
# the value of the CMake variable named 'VARIABLE' in the output file
configure_file(Doxyfile.in Doxyfile @ONLY)

# Run Doxygen
add_custom_command(
  # What this command generates
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/html/index.html"
  # Actually run doxygen
  COMMAND ${DOXYGEN_EXECUTABLE}
  # ... in the same directory as we generated the Doxyfile...
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  # Output requires regeneration when
  # i   - we modify the Doxygen configuration
  # ii  - the sources being documented change
  # iii - any auxillary inputs change
  DEPENDS Doxyfile.in ${PROJECT_SOURCE_DIR}/MPAGSCipher ${PROJECT_SOURCE_DIR}/README.md
  # Log that the command is run
  COMMENT "Doxygenating ${PROJECT_NAME}"
  )

# However, adding a command doesn't change anything in the build
# system - need to create a target that depends on the output of the
# command.
add_custom_target(
  # Name of the target - e.g. in Makefiles we can run 'make doc'
  doc
  # Add this target to the default target - i.e. documentation is
  # always built when building the whole project
  ALL
  # Make it depend on the output of the custom command
  DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/html/index.html"
  )

