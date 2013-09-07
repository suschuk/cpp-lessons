#include "Client.h"


Client::Client(const Client& client) : _name(client._name) , _mail(client._mail) , _telNo(client._telNo){}

Client::Client(std::string name, std::string mail, std::string telNo) : _name(name) , _mail(mail) , _telNo(telNo){}

std::string Client::Name() const {return _name;}
std::string Client::Mail() const{ return _mail;}
std::string Client::TelNo() const{ return _telNo;}

