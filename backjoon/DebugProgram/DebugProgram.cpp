#include <iostream>
#include <memory>
#include <string>
int main() {
    // Creating a shared_ptr to an integer

    std::shared_ptr<std::string> str = std::make_shared<std::string>("Hellow");
    std::shared_ptr<std::string> name = str;

    std::cout << *name << std::endl; // 값이 나옴
    std::cout << name << std::endl; // 주소값이 나옴


    return 0;
}