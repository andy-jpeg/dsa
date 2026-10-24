cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

message(VERBOSE "Executing patch step for mbedtls")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "C:/Users/sarae/OneDrive/Documents/GitHub/dsa/cmake-build-debug/_deps/mbedtls-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[C:/Program Files/JetBrains/CLion 2025.3.1.1/bin/cmake/win/x64/bin/cmake.exe]====] [====[-DMBEDTLS_DIR=C:/Users/sarae/OneDrive/Documents/GitHub/dsa/cmake-build-debug/_deps/mbedtls-src]====] [====[-P]====] [====[C:/Users/sarae/OneDrive/Documents/GitHub/dsa/cmake-build-debug/_deps/sfml-src/tools/mbedtls/PatchMbedTLS.cmake]====]
)

endblock()
