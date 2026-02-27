#include "RegistryStub.h"

RegistryStub &RegistryStub::instance()
{
    static RegistryStub inst;
    return inst;
}

bool RegistryStub::setValue(const std::string &key, const std::string &name, const std::string &value)
{
    data[key][name] = value;
    return true;
}

bool RegistryStub::getValue(const std::string &key, const std::string &name, std::string &value)
{
    auto it = data.find(key);
    if (it == data.end())
        return false;
    auto it2 = it->second.find(name);
    if (it2 == it->second.end())
        return false;
    value = it2->second;
    return true;
}
