
#include <iostream>
#include <fstream>
#include "./json/json.h"


int main()
{
    // Read JSON file
    std::ifstream file("./json/Data/player.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open JSON file." << std::endl;
        return 1;
    }

    Json::Value jsonData;
    file >> jsonData;
    file.close();

    
   
    for (const auto& player : jsonData) 
    {
        // Access JSON data
        std::string type = player["type"].asString();
        std::string name = player["name"].asString();
        int age = player["age"].asInt();
        int Level = player["Level"].asInt();
        int health = player["stats"]["health"].asInt();
        int attack = player["stats"]["attack"].asInt();
        int defense = player["stats"]["defense"].asInt();

        // Print JSON data
        std::cout << "Type: " << type << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Level: " << Level << std::endl;
        std::cout << "health: " << health << std::endl;
        std::cout << "attack: " << attack << std::endl;
        std::cout << "defense: " << defense << std::endl;
        std::cout << "\n" << std::endl;
    }
    for (const auto& monster : jsonData)
    {
        // Access JSON data
        std::string type = monster["type"].asString();
        std::string name = monster["name"].asString();
        int Level = monster["Level"].asInt();
        int health = monster["stats"]["health"].asInt();
        int attack = monster["stats"]["attack"].asInt();
        int defense = monster["stats"]["defense"].asInt();
        int exp = monster["stats"]["exp"].asInt();

        // Print JSON data
        std::cout << "Type: " << type << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Level: " << Level << std::endl;
        std::cout << "health: " << health << std::endl;
        std::cout << "attack: " << attack << std::endl;
        std::cout << "defense: " << defense << std::endl;
        std::cout << "exp: " << exp << std::endl;
        std::cout << "\n" << std::endl;
    }
    return 0;
}
