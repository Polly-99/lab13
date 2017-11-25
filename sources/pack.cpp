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
	std::fstream file ("Person.yml", std::fstream::out);

	std::cout << "Enter data to fields of the Person structure." << std::endl << "First name:" << std::endl;
	std::cin >> You.first_name;
	std::cout << std::endl << "Last name:" << std::endl;
	std::cin >> You.last_name;
	std::cout << std::endl << "Email:" << std::endl;
	std::cin >> You.email.nickname;
	std::string null_str, age_str;
	std::cout << std::endl << "Age(optional):" << std::endl;
	std::getline(std::cin, null_str);
	std::getline(std::cin, age_str);
	if(age_str.size() != 0) {
        	You.age = std::stoi(age_str);
	}
	std::cout << std::endl << "Phone (optional):" << std::endl;
	std::getline(std::cin, You.phone);

	int pos = You.email.nickname.find("@");
	if (pos == -1)
	{
		std::cout << std::endl << "ERROR!!! Wrong email" << std::endl;
		return -1;
	}
	You.email.server = You.email.nickname.substr(pos + 1, You.email.nickname.size());
	You.email.nickname = You.email.nickname.substr(0, pos);	

	YAML::Emitter out;
	out << YAML::BeginMap;
	out << YAML::Key << "first_name";
	out << YAML::Value << You.first_name;
	out << YAML::Key << "last_name";
	out << YAML::Value << You.last_name;
	out << YAML::Key << "nickname";
	out << YAML::Value << You.email.nickname;
	out << YAML::Key << "server";
	out << YAML::Value << You.email.server;
	out << YAML::Key << "age";
	out << YAML::Value << You.age;
	out << YAML::Key << "phone";
	out << YAML::Value << You.phone;
	out << YAML::EndMap;
	out << YAML::Newline;


	file << out.c_str();
	file.close();
	
	return 0;
}
