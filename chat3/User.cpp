#include "User.h"
#include <memory>



User::User(std::string password, std::string userName,int newUserID):password(password),userName(userName), newUserID(newUserID){}

User::User()
{
}

std::string User::getPassword()
{
	return password;
}

std::string User::getUserName()
{
	return userName;
}

int User::getNewUserID()
{
	return newUserID;
}






