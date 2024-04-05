#include "User.h"

User::User(std::string password, std::string userName,int newUserID):password(password),userName(userName), newUserID(newUserID){}

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


