#pragma once
#include <vector>
#include <string>
class User
{
private:
	
	std::string password;
	std::string userName;
		
public:
	User(std::string password, std::string userName );
	std::string getPassword();
	std::string getUserName();
	


};

