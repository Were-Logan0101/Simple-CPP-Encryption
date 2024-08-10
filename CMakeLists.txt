cmake_minimum_required(VERSION 3.24)
project(encryptApp)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_COMPILER "gcc.exe")
set(CMAKE_CXX_COMPILER "g++.exe")
include_directories(crypto)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static-libgcc -static-libstdc++")
add_executable(encrypt
    main.cpp
    crypto/md5.c
)
set_target_properties(encrypt PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/.."
    OUTPUT_NAME "encrypt"
    PREFIX ""
    SUFFIX ".exe"
)