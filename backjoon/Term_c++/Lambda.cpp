#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> numbers = { 5, 2, 8, 1, 9 };

    // Sort the vector in descending order using a lambda function
          std::sort(numbers.begin(), numbers.end(), [](int a, int b)
        {
            return a > b;
        });

    // Print the sorted vector
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    //// Example 1: A lambda function that adds two numbers
    //auto add = [](int a, int b) -> int {
    //    return a + b;
    //};

    //int result = add(3, 5);
    //std::cout << "Result: " << result << std::endl;

    //// Example 2: A lambda function with a capture list
    //int multiplier = 2;
    //auto multiply = [multiplier](int value) -> int {
    //    return value * multiplier;
    //};

    //int multipliedResult = multiply(4);
    //std::cout << "Multiplied Result: " << multipliedResult << std::endl;

    return 0;
}