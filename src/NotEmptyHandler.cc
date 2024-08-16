#include "BaseHandler.hpp"
#include "NotEmptyHandler.hpp"
#include "Command.hpp"


#include <string>
#include <string_view>

std::string NotEmptyHandler::Handle(Command* command)
{
    // checks if the message is empty

    if (command->Get().empty())
    {
        return "Please enter a message.";
    }

    return BaseHandler::Handle(command);
}
