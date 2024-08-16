#pragma once

#include "BaseHandler.hpp"

#include <string>
#include <string_view>

class NotEmptyHandler : public BaseHandler
{
public:
    std::string Handle(Command* command) override;
};
