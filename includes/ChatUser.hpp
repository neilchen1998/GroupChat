#pragma once

#include "Subscriber.hpp"

#include <string>
#include <string_view>

class ChatUser : public Subscriber
{
public:
    ChatUser(const std::string& userName = "default");
    ~ChatUser();

    void Notify(std::string_view publisherName, std::string_view msg) override;

    std::string GetName() const override;

    unsigned int GetID() const override;

private:
    std::string userName;
    unsigned int userID;
};
