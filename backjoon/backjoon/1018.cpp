#include <iostream>

using namespace std;

int main()
{
	int N, M;
	int result[50];
	int count = 0;;
	cin >> N;
	cin >> M;

	char board[50][50];
	//board[N][M]

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			char aa;
			cin >> aa;
			board[N][M] = aa;
		}
	}

	if (board[0][0] == 'B')
	{
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i += 2) //Â¦¼ö 0 ,2 ,4...
			{
				if (board[j][i] == 'W') //B¿©¾ßÇÔ
				{
					
				}
			}
			for (int i = 1; i < M; i += 2) //È¦¼ö 1,3,5...
			{
				if (board[j][i] == 'B')//W¿©¾ßÇÔ 
				{
					
				}
			}
		}
	}
	else if (board[0][0] == 'W') 
	{
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i += 2) //Â¦¼ö 0 ,2 ,4...
			{
				if (board[j][i] == 'B') //W
				{
					
				}
			}
			for (int i = 1; i < M; i += 2) //È¦¼ö 1,3,5...
			{
				if (board[j][i] == 'W')//B
				{
					
				}
			}
		}
	}
	
	cout << count;


}
