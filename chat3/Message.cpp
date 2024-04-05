#include "Message.h"
Message::Message(std::string text, std::string otpravitel):text(text), otpravitel(otpravitel){}
Message::Message(){}

std::string Message::getText()
{
	return text;
}

std::string Message::getOtpravitel()
{
	return otpravitel;
}

std::string Message::getPolychatel()
{
	return polychatel;
}


