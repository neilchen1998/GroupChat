#pragma once

#include "Subscriber.hpp"
#include "Publisher.hpp"

#include <string>
#include <string_view>
#include <unordered_map>

class ChatGroup : public Publisher
{
public:
    ChatGroup(const std::string& groupName);
    ~ChatGroup();

    void Subscribe(Subscriber* subscriber);
    void Unsubscribe(Subscriber* subscriber);
    void Publish(std::string_view msg);

private:
    std::string groupName;
    std::unordered_map<unsigned int, Subscriber*> subscriberList;
};
