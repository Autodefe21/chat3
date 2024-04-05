#pragma once
#include <vector>
#include <string>
#include "Message.h"
class User
{
private:
	std::string password;
	std::string userName;
	
public:
	
	int newUserID;
	User(std::string password, std::string userName, int newUserID);
	User();
	std::vector<Message> messages;
	std::string getPassword();
	std::string getUserName();
	int getNewUserID();
};
