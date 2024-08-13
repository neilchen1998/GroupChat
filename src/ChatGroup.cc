#include "Subscriber.hpp"
#include "ChatGroup.hpp"

#include <string>
#include <string_view>
#include <algorithm>

ChatGroup::ChatGroup(const std::string &groupName) : groupName(groupName)
{
}

ChatGroup::~ChatGroup()
{
}

void ChatGroup::Subscribe(Subscriber *subscriber)
{
    const auto newSubscriberID = subscriber->GetID();
    if (subscriberList.find(newSubscriberID) != subscriberList.end())
    {
        return;
    }

    subscriberList.insert(std::make_pair(newSubscriberID, subscriber));
}

void ChatGroup::Unsubscribe(Subscriber *subscriber)
{
    const auto targetSubscriberID = subscriber->GetID();
    if (subscriberList.find(targetSubscriberID) == subscriberList.end())
    {
        return;
    }

    subscriberList.erase(targetSubscriberID);
}

void ChatGroup::Publish(std::string_view msg)
{
    for (const auto [_, sub] : subscriberList)
    {
        sub->Notify(groupName, msg);
    }
}
