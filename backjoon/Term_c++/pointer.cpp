#include <iostream>


int main()
{
	int normal = 5; //������ ����
	int* pointer; // ������ ������ ����   ������ ������ �ּҰ��� ���� �����ϴ�.

	pointer = &normal; //&������ �Ϲ� ���� �տ� ���̸� �� ������ �ּҰ� ���� pointer������ ���� normal�� �ּҰ��� ���� ���� ����Ű�� ������ 
	std::cout << "pointer == " << pointer << std::endl; // �ּҰ��� ����
	std::cout << "*pointer ==" << *pointer << std::endl; //������ ������ *�� �ٿ��ָ� �ּҰ��� �ƴ� ���� ����


	//void* vpointer = &normal; // void�� ������   ��� �ڷ��� �����͵� ���� �� ����
	//auto* apointer = &normal; // auto�� ����Ѱ���?

	//std::cout << "vpointer ==  " << (int*)vpointer << std::endl; // �ּҰ��� ����
	//std::cout << "apointer ==" << *apointer << std::endl; //������ ������ *�� �ٿ��ָ� �ּҰ��� �ƴ� ���� ����

	normal = 42;

	void* vpointer = &normal;
	int* ipointer = static_cast<int*>(vpointer);// ���� �� ��ȯ ���ְ� ���
	std::cout << "Value using void pointer: " << *ipointer << std::endl;

	auto* apointer = &normal;
	std::cout << "Value using auto pointer: " << *apointer << std::endl;

	//���� ���̰� ���� auto* �����ʹ� �̴ϼȶ������� ������� ������ �ڵ����� �߷��ϰ� ĳ�������� �ʰ� ����Ű�� ������ ������ ���� �׼����� �� �ִ�.
	//�����͸� Ư�� ������ �������� ��������� ĳ�������� �ʰ� ���� �������ϰų� ������ ����� ������ �� �����ϴ�.
	return 0;
}