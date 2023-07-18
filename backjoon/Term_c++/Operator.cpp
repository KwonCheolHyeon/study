#include <iostream>
using namespace std;

class wowcat
{
public:
	// ���� ���1
	int operator() (int iArg1, int iArg2)
	{
		int iNum = iArg1 + iArg2;

		return iNum;
	}

	// ���� ���2
	int operator() (int, int, int);
};

// ���� ���2
int wowcat::operator() (int iArg1, int iArg2, int iArg3)
{
	int iNum = iArg1 + iArg2 + iArg3;

	return iNum;
}


int main()
{
	wowcat Obj1;

	cout << "��� ��� 1-1 : " << Obj1.operator()(1, 2) << endl;
	cout << "��� ��� 1-2 : " << Obj1(2, 3) << endl << endl;

	cout << "��� ��� 2-1 : " << Obj1.operator()(1, 2, 3) << endl;
	cout << "��� ��� 2-2 : " << Obj1(2, 3, 4) << endl << endl;

	// �Լ� ������ ���
	int (wowcat:: * fp1)(int, int) = &wowcat::operator();	// 1
	int (wowcat:: * fp2)(int, int, int) = &wowcat::operator();	// 2
	cout << "�Լ� ������ 1 : " << (Obj1.*fp1)(10, 100) << endl;
	cout << "�Լ� ������ 2 : " << (Obj1.*fp2)(10, 100, 1000) << endl;

	return 0;
}