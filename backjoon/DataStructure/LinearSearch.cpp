#include "LinearSearch.h"

int LinearSearch::LSearch(int ar[], int len, int target)
{
	int index;
	for (index = 0; index < len; index++) 
	{
		if (ar[index] == target) 
		{
			return index;
		}
	}
	return -1;
}

int LinearSearch::Run()
{
	int arr[] = { 3,5,2,4,9 };
	int idx;
	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1) 
	{
		std::cout << "Å½»ö ½ÇÆĞ" << "\n";
	}
	else 
	{
		std::cout << "Å¸°Ù ÀúÀå ÀÎµ¦½º:" << idx << "\n";
	}

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
	{
		std::cout << "Å½»ö ½ÇÆĞ" << "\n";
	}
	else
	{
		std::cout << "Å¸°Ù ÀúÀå ÀÎµ¦½º:" << idx << "\n";
	}

	return 0;
}
