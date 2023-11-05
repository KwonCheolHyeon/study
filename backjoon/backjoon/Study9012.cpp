#include "Study9012.h"

void compareCommend(const std::string& _com)
{
    
    int left = 0;
    int right = 0;
    char lef = '(';
    char righ = ')';
    
    for (int index = 0; index < _com.length(); index++)
    {
        if (_com[index] == lef) 
        {
            left++;
            right--;
        }
        else if (_com[index] == righ) 
        {
            if (left == 0) 
            {
                left = 100;
                break;
            }
            right++;
            left--;
        }
    }

    if (left == right) 
    {
        std::cout << "YES" << std::endl;
    }
    else 
    {
        std::cout << "NO" << std::endl;
    }

}


int Run() 
{
    int N = 0;
    std::cin >> N;
    std::cin.ignore();

    for (int index = 0; index < N; index++) 
    {
        std::string commend;
        std::cin >> commend;
        compareCommend(commend);
    }


    return 0;

}

