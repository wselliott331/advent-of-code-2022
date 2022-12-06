#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

    std::ifstream file("../input.txt");
    std::string str;
    std::vector<int> calories;
    int max_cal;
    int running_sum = 0;

    while (std::getline(file, str))
        {
            if(str.size() >0)
                {
                    running_sum += std::stoi(str);
                }
            else
                {
                    calories.push_back(running_sum);
                    running_sum = 0;
                }
        }
    
    
    std::cout << "Highest calories: " << *std::max_element( calories.begin(), calories.end() ) << std::endl;
    return 0;    
}