#pragma once

#include "ChatGroup.hpp"

#include <string>
#include <string_view>

class Handler
{
public:
    virtual ~Handler() = default;
    virtual Handler* SetNext(Handler* nextHandler) = 0;
    virtual std::string Handle(ChatGroup* group, std::string_view msg) = 0;
};