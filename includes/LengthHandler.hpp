#pragma once

#include "BaseHandler.hpp"
#include "ChatGroup.hpp"

#include <string>
#include <string_view>

class LengthHandler : public BaseHandler
{
public:
    LengthHandler(unsigned int maxLength = 50);
    std::string Handle(ChatGroup* group, std::string_view msg) override;

private:
    unsigned int maxLength;
};