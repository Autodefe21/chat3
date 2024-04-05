#pragma once
#include <vector>
#include "User.h"
#include "Message.h"
#include <memory>
class Chat
{
private:
	std::shared_ptr<User> currentUser;
	std::vector<std::shared_ptr<User>> users;
	std::vector<std::shared_ptr<Message>> messages;
public:
	
	//std::vector<Message> messages;
	//std::vector<User> users;
	std::vector<std::shared_ptr<Message>> getMessage();
	
	Chat();
	bool registerUser(std::string userName, std::string password);
	bool login(std::string userName, std::string password);
	void logout();
	void addMessage(std::string text, std::string otpravitel);
	void userMessage(std::string text, std::string otpravitel, std::string polychatel);
};

