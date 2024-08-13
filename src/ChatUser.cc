#include "ChatUser.hpp"

#include <iostream>
#include <string>
#include <string_view>
#include <random>
#include <limits>

static std::random_device rd;
std::mt19937_64 eng(rd());
std::uniform_int_distribution<unsigned int> distrib;

ChatUser::ChatUser(const std::string& userName) : userName(userName)
{
    userID = distrib(eng);
    std::cout << userName << " is created with an ID of " << userID << "\n";
}

ChatUser::~ChatUser()
{
}

void ChatUser::Notify(std::string_view publisherName, std::string_view msg)
{
    std::cout << userName << " receives a new message from " << publisherName << ": " << msg << "\n";
}

std::string ChatUser::GetName() const
{
    return userName;
}

unsigned int ChatUser::GetID() const
{
    return userID;
}
