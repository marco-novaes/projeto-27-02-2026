#include "GenericPacker.h"
#include <fstream>
#include <zlib.h>

bool GenericPacker::addFile(const std::string &path, const std::string &virtualName)
{
    std::ifstream in(path, std::ios::binary);
    if (!in)
        return false;

    std::vector<unsigned char> buf((std::istreambuf_iterator<char>(in)),
                                   std::istreambuf_iterator<char>());
    entries.push_back({virtualName, std::move(buf), false});
    return true;
}

bool GenericPacker::writePackage(const std::string &hostExe, const std::string &outputExe)
{
    // stub: copy host exe and append a simple archive header
    std::ifstream in(hostExe, std::ios::binary);
    if (!in)
        return false;

    std::ofstream out(outputExe, std::ios::binary);
    if (!out)
        return false;

    out << in.rdbuf();

    // write a simple header: number of entries followed by each entry
    uint32_t count = (uint32_t)entries.size();
    out.write(reinterpret_cast<const char *>(&count), sizeof(count));

    for (auto &e : entries)
    {
        uint32_t nameLen = (uint32_t)e.virtualName.size();
        out.write(reinterpret_cast<const char *>(&nameLen), sizeof(nameLen));
        out.write(e.virtualName.c_str(), nameLen);

        uint32_t dataLen = (uint32_t)e.data.size();
        out.write(reinterpret_cast<const char *>(&dataLen), sizeof(dataLen));
        out.write(reinterpret_cast<const char *>(e.data.data()), dataLen);
    }

    return true;
}

bool GenericPacker::compressBuffer(std::vector<unsigned char> &buf)
{
    // stubbed: placeholder for zlib compression
    return false;
}
