#include "PostMsgHandler.hpp"
#include "Command.hpp"

#include <string>
#include <string_view>

std::string PostMsgHandler::Handle(Command* command)
{
    // publishes the message
    command->Execute();

    return "Message is sent!";
}
