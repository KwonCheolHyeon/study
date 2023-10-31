#include <iostream>


int main()
{
	int normal = 5; //정수형 변수
	int* pointer; // 정수형 포인터 변수   포인터 변수는 주소값만 저장 가능하다.

	pointer = &normal; //&참조를 일반 변수 앞에 붙이면 그 변수의 주소값 따라서 pointer변수는 현재 normal의 주소값과 같은 값을 가르키고 있으며 
	std::cout << "pointer == " << pointer << std::endl; // 주소값이 나옴
	std::cout << "*pointer ==" << *pointer << std::endl; //포인터 변수에 *를 붙여주면 주소값이 아닌 값이 나옴


	//void* vpointer = &normal; // void형 포인터   어떠한 자료형 포인터든 가질 수 있음
	//auto* apointer = &normal; // auto와 비슷한건지?

	//std::cout << "vpointer ==  " << (int*)vpointer << std::endl; // 주소값이 나옴
	//std::cout << "apointer ==" << *apointer << std::endl; //포인터 변수에 *를 붙여주면 주소값이 아닌 값이 나옴

	normal = 42;

	void* vpointer = &normal;
	int* ipointer = static_cast<int*>(vpointer);// 강제 형 변환 해주고 사용
	std::cout << "Value using void pointer: " << *ipointer << std::endl;

	auto* apointer = &normal;
	std::cout << "Value using auto pointer: " << *apointer << std::endl;

	//둘은 차이가 있음 auto* 포인터는 이니셜라이저를 기반으로 유형을 자동으로 추론하고 캐스팅하지 않고 가리키는 데이터 유형에 직접 액세스할 수 있다.
	//포인터를 특정 포인터 유형으로 명시적으로 캐스팅하지 않고 직접 역참조하거나 포인터 산술을 수행할 수 없습니다.
	return 0;
}