#pragma once

#include "BaseHandler.hpp"
#include "Command.hpp"

#include <string>
#include <string_view>

class PostMsgHandler : public BaseHandler
{
public:
    std::string Handle(Command* command) override;
};
