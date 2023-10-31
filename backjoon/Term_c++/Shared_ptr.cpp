#include <iostream>
#include <memory>
#include <string>
int main() {
    // Creating a shared_ptr to an integer

    std::shared_ptr<std::string> str = std::make_shared<std::string>("Hellow");
    std::shared_ptr<std::string> name = str;

    std::cout << *name << std::endl; // ���� ����
    std::cout << name << std::endl; // �ּҰ��� ����


    return 0;
}