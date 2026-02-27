#pragma once

// Interface for a simple virtual file system that serves data from memory.
// In a real packer this would intercept or hook file-related WinAPI calls.

#include <string>
#include <vector>

class VirtualFS
{
public:
    static VirtualFS &instance();

    // initialize with archive blob (from memory)
    bool initialize(const void *archiveData, size_t length);

    // open a virtual file
    std::vector<unsigned char> readFile(const std::string &path);

private:
    VirtualFS() = default;
    // internal representation of files, etc.
};
