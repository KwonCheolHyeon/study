#include <iostream>
using namespace std;

class wowcat
{
public:
	// 정의 방법1
	int operator() (int iArg1, int iArg2)
	{
		int iNum = iArg1 + iArg2;

		return iNum;
	}

	// 정의 방법2
	int operator() (int, int, int);
};

// 정의 방법2
int wowcat::operator() (int iArg1, int iArg2, int iArg3)
{
	int iNum = iArg1 + iArg2 + iArg3;

	return iNum;
}


int main()
{
	wowcat Obj1;

	cout << "사용 방법 1-1 : " << Obj1.operator()(1, 2) << endl;
	cout << "사용 방법 1-2 : " << Obj1(2, 3) << endl << endl;

	cout << "사용 방법 2-1 : " << Obj1.operator()(1, 2, 3) << endl;
	cout << "사용 방법 2-2 : " << Obj1(2, 3, 4) << endl << endl;

	// 함수 포인터 방법
	int (wowcat:: * fp1)(int, int) = &wowcat::operator();	// 1
	int (wowcat:: * fp2)(int, int, int) = &wowcat::operator();	// 2
	cout << "함수 포인터 1 : " << (Obj1.*fp1)(10, 100) << endl;
	cout << "함수 포인터 2 : " << (Obj1.*fp2)(10, 100, 1000) << endl;

	return 0;
}