#pragma once

#include <string>
#include <string_view>

class Subscriber
{
public:
    virtual void Notify(std::string_view publisherName, std::string_view msg) = 0;
    virtual std::string GetName() const = 0;
    virtual unsigned int GetID() const = 0;
};
