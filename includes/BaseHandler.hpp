#pragma once

#include "Handler.hpp"
#include "ChatGroup.hpp"
#include "Command.hpp"

#include <string>
#include <string_view>

class BaseHandler : public Handler
{
public:
    ~BaseHandler();

    Handler* SetNext(Handler* nextHandler) override;

    std::string Handle(Command* command) override;

protected:
    Handler* next;
};
