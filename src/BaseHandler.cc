#include "BaseHandler.hpp"

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

std::string BaseHandler::Handle(ChatGroup *group, std::string_view msg)
{
    // checks if there is another handler down the chain
    if (this->next)
    {
        return next->Handle(group, msg);
    }

    // reaches to the end of the chain
    return "Success!";
}
