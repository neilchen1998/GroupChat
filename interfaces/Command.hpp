#pragma once

#include <string>

class Command
{
public:
    virtual ~Command() = default;
    virtual void Execute() = 0;
    virtual std::string Get() = 0;
};
