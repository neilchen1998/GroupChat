#pragma once

#include "Command.hpp"

#include <string>
#include <string_view>

class Handler
{
public:
    virtual ~Handler() = default;
    virtual Handler* SetNext(Handler* nextHandler) = 0;
    virtual std::string Handle(Command* command) = 0;
};
