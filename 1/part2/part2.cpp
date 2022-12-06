#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>

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
    

    sort(calories.begin(), calories.end(), std::greater<int>());

    calories.resize(3);

    std::cout << "Total calories: " << std::accumulate(calories.begin(), calories.end(), 0);

    return 0;    
}