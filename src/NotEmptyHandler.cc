#include "BaseHandler.hpp"
#include "NotEmptyHandler.hpp"

#include <string>
#include <string_view>

std::string NotEmptyHandler::Handle(ChatGroup *group, std::string_view msg)
{
    // checks if the message is empty

    if (msg.empty())
    {
        return "Please enter a message.";
    }

    return BaseHandler::Handle(group, msg);
}
