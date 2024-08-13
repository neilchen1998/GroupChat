#pragma once

#include "BaseHandler.hpp"
#include "ChatGroup.hpp"

#include <string>
#include <string_view>

class PostMsgHandler : public BaseHandler
{
public:
    std::string Handle(ChatGroup* group, std::string_view msg) override;
};