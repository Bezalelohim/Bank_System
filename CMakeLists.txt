cmake_minimum_required(VERSION 3.5.0) 
project(Bank_System) 


# Set the C++ standard to C++11 (or a later version if required)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF) # this line is optional, it ensures -std=c++11 rather than -std=gnu++11

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OS_BITNESS "64bit")
else()
    set(OS_BITNESS "32bit")
endif()

set(BIN_OUTPUT_DIRECTORY "bin/${OS_BITNESS}/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/${BIN_OUTPUT_DIRECTORY})


# Include directories for header files
include_directories(${PROJECT_SOURCE_DIR}/include)


# Add source files to the build
add_executable(Bank_System
    src/main.cpp
    src/account.cpp
    src/customer.cpp
    src/database_operations.cpp
    src/transaction.cpp
)

# Find OpenSSL package
find_package(OpenSSL REQUIRED)

# Link with OpenSSL and MySQL Connector/C++ libraries
target_link_libraries(Bank_System PRIVATE OpenSSL::SSL OpenSSL::Crypto mysqlcppconn8)
