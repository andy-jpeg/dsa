cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

message(VERBOSE "Executing patch step for libssh2")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "C:/Users/sarae/OneDrive/Documents/GitHub/dsa/cmake-build-debug/_deps/libssh2-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[C:/Program Files/JetBrains/CLion 2025.3.1.1/bin/cmake/win/x64/bin/cmake.exe]====] [====[-DLIBSSH2_DIR=C:/Users/sarae/OneDrive/Documents/GitHub/dsa/cmake-build-debug/_deps/libssh2-src]====] [====[-DMODULES_DIR=C:/Users/sarae/OneDrive/Documents/GitHub/dsa/cmake-build-debug/_deps/sfml-src/src/SFML/Network/../../../cmake/Modules]====] [====[-P]====] [====[C:/Users/sarae/OneDrive/Documents/GitHub/dsa/cmake-build-debug/_deps/sfml-src/tools/libssh2/PatchLibssh2.cmake]====]
)

endblock()
