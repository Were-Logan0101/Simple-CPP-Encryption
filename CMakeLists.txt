cmake_minimum_required(VERSION 3.24)
project(encryptApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)

# Specify the compilers (adjust paths if needed)
set(CMAKE_C_COMPILER "C:/Users/ahmed/AppData/Local/Nuitka/Nuitka/Cache/downloads/gcc/x86_64/13.2.0-16.0.6-11.0.1-msvcrt-r1/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Users/ahmed/AppData/Local/Nuitka/Nuitka/Cache/downloads/gcc/x86_64/13.2.0-16.0.6-11.0.1-msvcrt-r1/mingw64/bin/g++.exe")

# Include directories
include_directories(crypto)

# Set the linker flags to make sure the resulting executable is statically linked
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static-libgcc -static-libstdc++")

# Add executable target
add_executable(encrypt
    main.cpp
    crypto/md5.c
)

set_target_properties(encrypt PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/.."  # This places encrypt.exe in the directory above the build directory
    OUTPUT_NAME "encrypt"
    PREFIX ""
    SUFFIX ".exe"
)
