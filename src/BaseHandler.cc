#include "BaseHandler.hpp"
#include "Command.hpp"

#include <string>
#include <string_view>

BaseHandler::~BaseHandler()
{
}

Handler *BaseHandler::SetNext(Handler *nextHandler)
{
    next = nextHandler;
    return nextHandler;
}

std::string BaseHandler::Handle(Command* command)
{
    // checks if there is another handler down the chain
    if (this->next)
    {
        return next->Handle(command);
    }

    // reaches to the end of the chain
    return "Success!";
}
