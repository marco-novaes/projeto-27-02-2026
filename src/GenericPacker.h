#pragma once
//versão 3
#include <string>
#include <vector>

class GenericPacker
{
public:
    // add a file to be embedded; the packer optionally compresses it
    bool addFile(const std::string &path, const std::string &virtualName);

    // write the packed executable to disk
    bool writePackage(const std::string &hostExe, const std::string &outputExe);

private:
    struct Entry
    {
        std::string virtualName;
        std::vector<unsigned char> data;
        bool compressed = false;
    };

    std::vector<Entry> entries;

    bool compressBuffer(std::vector<unsigned char> &buf);
};
