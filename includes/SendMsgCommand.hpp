#pragma once

#include "Command.hpp"
#include "ChatGroup.hpp"

#include <string>

class SendMsgCommand : public Command
{
public:
    SendMsgCommand(ChatGroup* chatGroup, std::string msg);
    void Execute();
    std::string Get() override;
private:
    ChatGroup* chatGroup;
    std::string msg;
};