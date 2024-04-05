#include "Chat.h"
#include "User.h"
#include "Message.h"
#include <iostream>
#include <vector>
#include <memory>

std::vector<std::shared_ptr<Message>> Chat::getMessage()
{
    std::vector<std::shared_ptr<Message>> userMessages;

    for ( auto& message : messages) {
        if (message->getPolychatel() == currentUser->getUserName() || message->getOtpravitel() == currentUser->getUserName()) {
            userMessages.push_back(message);
        }
    }
    return userMessages;
}


Chat::Chat()
{
}



bool Chat::registerUser( std::string userName, std::string password)
{
    for (const std::shared_ptr<User>& user : users) {
        if (user->getUserName() == userName) {
            std::cout << "Имя пользователя уже существует " << userName << std::endl;
            return false;
        }
    }
    int newUserID = users.size() + 1;
    std::shared_ptr<User> newUser = std::make_shared<User>(password, userName, newUserID);
    users.push_back(newUser);
    std::cout << "Пользователь зарегистрирован: id " << newUserID << std::endl;
    return true;
}

bool Chat::login( std::string userName, std::string password)
{
    for (const auto& user : users) {
        if (user->getUserName() == userName && user->getPassword() == password) {
            std::cout << "Вход выполнен: " << userName << " " << "id: " << user->getNewUserID() << std::endl;
            currentUser = user;
            return true;
        }
    }
    std::cout << "Неправильные данные входа." << std::endl;
    return false;

}

void Chat::logout()
{
    if (currentUser) {
        std::cout << "Logging out " << currentUser->getUserName() << std::endl;
        currentUser = nullptr;
    }
    else {
        std::cout << "No user logged in" << std::endl;
    }
}

void Chat::addMessage(std::string text, std::string otpravitel)
{
    bool senderExists = false;
    for (const auto& user : users) {
        if (user->getUserName() == otpravitel) {
            senderExists = true;
            break;
        }
    }

    if (senderExists) {
        std::shared_ptr<Message> newMessage = std::make_shared<Message>(text, otpravitel);
        messages.push_back(newMessage);
    }
    else {
        std::cout << "Пользователь " << otpravitel << " не найден." << std::endl;
    }
}

void Chat::userMessage(std::string text, std::string otpravitel, std::string polychatel)
{
    bool userOn = false;
    for (const auto& user : users) {
        if (user->getUserName() == polychatel) {
            std::shared_ptr<Message> newMessage = std::make_shared<Message>(text, otpravitel);
            messages.push_back(newMessage);
            userOn = true;
            break;
        }
    }

    if (!userOn) {
        std::cout << "Пользователь " << polychatel << " не найден." << std::endl;
    }

    
}





//for (User& user : users) {
    //if (user.getUserName() != otpravitel) {
    //    messages.push_back(Message(text, otpravitel));

   // }
//}

    



