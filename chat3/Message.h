#pragma once
#include <string>
#include <vector>

class Message
{
private:
	
	std::string text;
	std::string otpravitel;
	std::string polychatel;
public:
	Message();
	Message(std::string text, std::string otpravitel);
	std::string getText();
	std::string getOtpravitel();
	std::string getPolychatel();

};

