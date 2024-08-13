#include "SendMsgCommand.hpp"
#include "ChatGroup.hpp"

#include <string>

SendMsgCommand::SendMsgCommand(ChatGroup* chatGroup, std::string msg) : chatGroup(chatGroup), msg(msg)
{

}

std::string SendMsgCommand::Get()
{
    return msg;
}

void SendMsgCommand::Execute()
{
    chatGroup->Publish(msg);
}