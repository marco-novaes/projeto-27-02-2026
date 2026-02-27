#include "GenericPacker.h"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        std::cout << "Usage: packer <host.exe> <out.exe> <file1> [file2 ...]\n";
        return 1;
    }

    std::string host = argv[1];
    std::string out = argv[2];

    GenericPacker packer;
    for (int i = 3; i < argc; ++i)
    {
        std::string path = argv[i];
        std::string virtualName = path; // for now just keep the original name
        if (!packer.addFile(path, virtualName))
        {
            std::cerr << "Failed to add " << path << "\n";
            return 1;
        }
    }

    if (!packer.writePackage(host, out))
    {
        std::cerr << "Failed to write package\n";
        return 1;
    }

    std::cout << "Package written to " << out << "\n";
    return 0;
}
