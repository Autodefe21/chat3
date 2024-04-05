#pragma once
#include <vector>
#include <string>
class User
{
private:
	
	std::string password;
	std::string userName;
	int newUserID;
public:
	User(std::string password, std::string userName,int newUserID);
	std::string getPassword();
	std::string getUserName();
	int getNewUserID();
};

