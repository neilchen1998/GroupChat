#include "Publisher.hpp"
#include "Subscriber.hpp"
#include "ChatGroup.hpp"
#include "ChatUser.hpp"
#include "Handler.hpp"
#include "NotEmptyHandler.hpp"
#include "LengthHandler.hpp"
#include "PostMsgHandler.hpp"

#include <iostream>
#include <memory>   // std::unique_ptr, std::make_unique

int main()
{
    // users
    std::unique_ptr<Subscriber> user1 = std::make_unique<ChatUser>("Neil");
    std::unique_ptr<Subscriber> user2 = std::make_unique<ChatUser>("Nick");
    std::unique_ptr<Subscriber> user3 = std::make_unique<ChatUser>("Granite");

    // chat groups
    std::unique_ptr<Publisher> group1 = std::make_unique<ChatGroup>("Devs");
    std::unique_ptr<Publisher> group2 = std::make_unique<ChatGroup>("HIL");

    // subscriptions
    group1->Subscribe(user1.get());
    group1->Subscribe(user2.get());
    group2->Subscribe(user1.get());
    group2->Subscribe(user3.get());

    // handlers
    std::unique_ptr<Handler> sendMsgHandlers = std::make_unique<BaseHandler>();
    std::unique_ptr<Handler> notEmptyHandler = std::make_unique<NotEmptyHandler>();
    std::unique_ptr<Handler> lengthHandler = std::make_unique<LengthHandler>(40);
    std::unique_ptr<Handler> postMsgHandler = std::make_unique<PostMsgHandler>();
    sendMsgHandlers->SetNext(notEmptyHandler.get())->SetNext(lengthHandler.get())->SetNext(postMsgHandler.get());

    // publishes messages (naive way)
    // group1->Publish("New user story is created!");
    // group2->Publish("Test report is ready!");

    {
        // tries to send an empty message
        std::string_view msg("");
        std::cerr << sendMsgHandlers->Handle(dynamic_cast<ChatGroup*>(group1.get()), msg) << std::endl;
    }

    {
        // tries to send a long message
        std::string_view msg("fadgagfagghafgafgatbajjhrthereriricauythuht");
        std::cerr << sendMsgHandlers->Handle(dynamic_cast<ChatGroup*>(group1.get()), msg) << std::endl;
    }

    {
        // tries to send a valid message on group 1
        std::string_view msg("New user story is created!");
        std::cerr << sendMsgHandlers->Handle(dynamic_cast<ChatGroup*>(group1.get()), msg) << std::endl;
    }

    {
        // tries to send a valid message on group 2
        std::string_view msg("Test report is ready!");
        std::cerr << sendMsgHandlers->Handle(dynamic_cast<ChatGroup*>(group2.get()), msg) << std::endl;
    }

    return 0;
}