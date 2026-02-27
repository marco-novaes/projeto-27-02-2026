#pragma once

// A simple in-memory registry stub.  Methods will mimic the WinAPI but
// operate on an isolated store.  The loader will patch registry calls to
// redirect to this implementation during execution of the packed app.

#include <string>
#include <map>

class RegistryStub
{
public:
    static RegistryStub &instance();

    bool setValue(const std::string &key, const std::string &name, const std::string &value);
    bool getValue(const std::string &key, const std::string &name, std::string &value);

private:
    RegistryStub() = default;
    std::map<std::string, std::map<std::string, std::string>> data;
};
