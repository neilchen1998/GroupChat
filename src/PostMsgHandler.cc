#include "BaseHandler.hpp"
#include "PostMsgHandler.hpp"

#include <string>
#include <string_view>

std::string PostMsgHandler::Handle(ChatGroup *group, std::string_view msg)
{
    // publishes the message
    group->Publish(msg);

    return "Message is sent!";
}
