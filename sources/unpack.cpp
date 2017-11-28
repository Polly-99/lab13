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

	YAML::Node doc = YAML::LoadFile("Person.yml");

	You.first_name = doc["first_name"].as<std::string>();
      	You.last_name = doc["last_name"].as<std::string>(); 
      	You.email.nickname = doc["nickname"].as<std::string>();
	You.email.server = doc["server"].as<std::string>();
      	You.age = doc["age"].as<size_t>();
	You.phone= doc["phone"].as<std::string>(); 

	std::string email = You.email.nickname + "@" + You.email.server;
	std::cout << "[Person]" << std::endl;
  	std::cout << "First name: " << You.first_name << std::endl;
  	std::cout << "Last name: " << You.last_name << std::endl;
  	std::cout << "Email: " << email << std::endl;
  	std::cout << "Age: " << You.age << std::endl;
	std::cout << "Phone: " << You.phone << std::endl;
	
	return 0;
}
