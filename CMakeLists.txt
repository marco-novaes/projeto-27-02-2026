cmake_minimum_required(VERSION 3.15)
project(GenericPacker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files for the packer tool
add_executable(packer
    src/main.cpp
    src/GenericPacker.cpp
    src/VirtualFS.cpp
    src/RegistryStub.cpp
)

# zlib is required for compression; find it on the system or use an external
find_package(ZLIB REQUIRED)
target_link_libraries(packer PRIVATE ZLIB::ZLIB)

# include directories
target_include_directories(packer PRIVATE src)

# for a real project you'd also set up installer, tests, etc.
