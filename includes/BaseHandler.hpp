#pragma once

#include "Handler.hpp"
#include "ChatGroup.hpp"

#include <string>
#include <string_view>

class BaseHandler : public Handler
{
public:
    ~BaseHandler();

    Handler* SetNext(Handler* nextHandler) override;

    std::string Handle(ChatGroup* group, std::string_view msg) override;

protected:
    Handler* next;
};