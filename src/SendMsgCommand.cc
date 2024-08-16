#include "SendMsgCommand.hpp"
#include "Publisher.hpp"

#include <string>
#include <string_view>

SendMsgCommand::SendMsgCommand(Publisher* chatGroup, std::string_view msg) : chatGroup(chatGroup), msg(msg)
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
