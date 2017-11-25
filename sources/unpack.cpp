#include <iostream>
#include <string>
#include <fstream>
#include "yaml-cpp/yaml.h"

struct Email {
	std::string nickname;
	std::string server;
};

struct Person {
	std::string  first_name;
	std::string  last_name;
	Email        email;
	size_t       age;
	std::string  phone;
};

int main()
{
	Person You;
	std::fstream file ("Person.yml", std::fstream::in);
	YAML::Parser parser(file);
	YAML::Node doc;
	parser.GetNextDocument(doc);

	doc["first_name"] >> You.first_name;
	doc["last_name"] >> You.last_name;
	doc["nickname"] >> You.email.nickname;
	doc["server"] >> You.email.server;
	doc["age"] >> You.age;
	doc["phone"] >> You.phone;
        
	std::string email = You.email.nickname + "@" + You.email.server;
	std::cout << "[Person]" << std::endl;
  	std::cout << "First name: " << You.first_name << std::endl;
  	std::cout << "Last name: " << You.last_name << std::endl;
  	std::cout << "Email: " << email << std::endl;
  	std::cout << "Age: " << You.age << std::endl;
	std::cout << "Phone: " << You.phone << std::endl;
	
	return 0;
}
