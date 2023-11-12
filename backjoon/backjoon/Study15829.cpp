#include "Study15829.h"
#include <map>

enum Command 
{
	a,
	b,
	c,
	d,
	e,
	f,
	g,
	h,
	i,
	j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
};

std::map<Command,int> commandMap =
{
	{a,1},
	{b,2},
	{c,3},
	{d,4},
	{e,5},
	{f,6},
	{g,7},
	{h,8},
	{9,9},
	{10,10},
	{11,11},
	{12,12},
	{13,13},
	{14,14},
	{15,15},
	{16,16},
	{17,17},
	{18,18},
	{19,19},
	{20,20},
	{21,21},
	{22,22},
	{23,23},
	{24,24},
	{25,25},
	{26,26}
};

int compareCommend(const std::string& _com);
void calcu(int _index);
int hap;
int count;

int main()
{
	int Number;
	char chData;

	std::cin >> Number;

	for (int index = 0; index < Number; index++) 
	{
		std::cin >> chData;
	}
	int a = 0;

}

int compareCommend(const std::string& _com) 
{
	
	switch (commandMap[_com]) {
		case 1:
		
		break;
	}


	return;
}

void calcu(int _index)
{
	for (int index = 0; index < count; index++)
	{


	}


	count++;

}