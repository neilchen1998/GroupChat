#pragma once

#include "Subscriber.hpp"

#include <string_view>

class Publisher
{
public:
    virtual void Subscribe(Subscriber* subscriber) = 0;
    virtual void Unsubscribe(Subscriber* subscriber) = 0;
    virtual void Publish(std::string_view msg) = 0;
};
