#include "BaseHandler.hpp"
#include "LengthHandler.hpp"

#include <string>
#include <string_view>

LengthHandler::LengthHandler(unsigned int maxLength) : maxLength(maxLength)
{
}

std::string LengthHandler::Handle(ChatGroup *group, std::string_view msg)
{
    // checks if the message within the length
    if (msg.length() >= maxLength)
    {
        return "Please enter a shorter message.";
    }

    return BaseHandler::Handle(group, msg);
}
