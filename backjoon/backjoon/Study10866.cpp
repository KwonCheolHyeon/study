#include "Study10866.h"

using namespace std;

deque<int> deq;

string commend1 = "push_front";
string commend2 = "push_back";
string commend3 = "pop_front";
string commend4 = "pop_back";
string commend5 = "size";
string commend6 = "empty";
string commend7 = "front";
string commend8 = "back";

void Run10866()
{
	int N = 0;
	int index;
	cin >> N;

	string commend;

	

	while (true)
	{
		for (int i = 0; i < N; i++) //실행할 명령
		{
			cin >> commend >> index;
			if (index != NULL) 
			{
				compareCommend(commend, index);
			}
			else 
			{
				compareCommend(commend);
			}
		}
	}


}

void compareCommend(string _com)
{
	
	
}

void compareCommend(string _com, int _index)
{
	
}
