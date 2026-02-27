#include "VirtualFS.h"

VirtualFS &VirtualFS::instance()
{
    static VirtualFS instance;
    return instance;
}

bool VirtualFS::initialize(const void *archiveData, size_t length)
{
    // TODO: parse the archive format and build internal maps
    (void)archiveData;
    (void)length;
    return true;
}

std::vector<unsigned char> VirtualFS::readFile(const std::string &path)
{
    // TODO: lookup file by path and return its data
    return {};
}
