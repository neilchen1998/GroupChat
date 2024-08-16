#pragma once

#include "Command.hpp"
#include "Publisher.hpp"

#include <string>
#include <string_view>

class SendMsgCommand : public Command
{
public:
    SendMsgCommand(Publisher* chatGroup, std::string_view msg);
    void Execute();
    std::string Get() override;
private:
    Publisher* chatGroup;
    std::string msg;
};
