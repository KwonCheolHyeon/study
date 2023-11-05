#include "Study10816.h"


void compare(std::vector<int> _a, std::vector<int> _b)
{
	std::vector<int> count;
	int countint = 0;

	for (int index = 0; index < _b.size(); index++) 
	{
		for (int number = 0; number < _a.size(); number++)
		{
			if (_b[index] == _a[number])
			{
				countint++;
			}
		}
		count.push_back(countint);
		countint = 0;
	}

	for (int index = 0; index < count.size(); index++) 
	{
		std::cout << count[index] << " ";
	}


}

int main()
{
	int N,M;

	std::vector<int> first;
	std::vector<int> second;
	

	std::cin >> N;

	for (int index = 0; index < N; index++) 
	{
		int saveFirst;
		std::cin >> saveFirst;
		first.push_back(saveFirst);
	}

	std::cin >> M;

	for (int index = 0; index < M; index++)
	{
		int saveFirst;
		std::cin >> saveFirst;
		second.push_back(saveFirst);
	}
	compare(first, second);

}