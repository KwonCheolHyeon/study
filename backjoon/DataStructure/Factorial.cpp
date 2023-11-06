#include "Factorial.h"

int Factorial::Facto(int n)
{
	int a = n - 1;
	if (a == 0) 
	{
		return 1;
	}
	else 
	{
		return n * Facto(n - 1);
	}
	
}

int Factorial::Run()
{

	std::cout << Facto(4);


	return 0;
}
