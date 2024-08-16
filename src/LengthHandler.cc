#include "BaseHandler.hpp"
#include "LengthHandler.hpp"

#include <string>
#include <string_view>

LengthHandler::LengthHandler(unsigned int maxLength) : maxLength(maxLength)
{
}

std::string LengthHandler::Handle(Command* command)
{
    // checks if the message within the length
    const auto len = command->Get().length();
    if (len >= maxLength)
    {
        return "Please enter a shorter message.";
    }

    return BaseHandler::Handle(command);
}
