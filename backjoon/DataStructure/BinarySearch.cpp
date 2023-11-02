#include "BinarySearch.h"

void BinarySearch::Run()
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	return ;
}

int BinarySearch::BSearch(int ar[], int len, int target)//이건 정렬되어있다는 조건하에 쓸 수 있다.
{
	int first = 0;
	int last = len - 1;
	int mid;
	while (first<=last)
	{
		mid = (first + last)/2;

		if (target == ar[mid]) 
		{
			return mid;
		}
		else 
		{
			if (target < ar[mid]) 
			{
				last = mid - 1;
			}
			else 
			{
				first = mid + 1;
			}
		}
	}

	return -1;
}
