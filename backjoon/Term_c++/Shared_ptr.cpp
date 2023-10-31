#include <iostream>
#include <memory>
#include <string>
int main() {
    // Creating a shared_ptr to an integer

    std::shared_ptr<std::string> str = std::make_shared<std::string>("Hellow");
    std::shared_ptr<std::string> name = str;

    std::cout << *name << std::endl; // °ªÀÌ ³ª¿È
    std::cout << name << std::endl; // ÁÖ¼Ò°ªÀÌ ³ª¿È


    return 0;
}