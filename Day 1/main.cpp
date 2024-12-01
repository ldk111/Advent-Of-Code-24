#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

void part_one() {
    std::ifstream MyReadFile("input.txt");

    std::string myText;

    std::vector<int> left_list;
    std::vector<int> right_list;

    int distance = 0;

    while (std::getline(MyReadFile, myText)) {

        int num = 0;

        for (int i = 0; i < myText.length(); i++) {

            if (isdigit(myText[i])) {

                 num = num * 10 + myText[i] - '0'; 

            } else {
                i += 2;
                left_list.push_back(num);
                num = 0;
            }
    
        }

        right_list.push_back(num);

    }

    std::sort(left_list.begin(), left_list.end());
    std::sort(right_list.begin(), right_list.end());

    for (int i = 0; i < left_list.size(); i++) {
        distance += std::abs(left_list[i] - right_list[i]);
    }

    std::cout << distance;
    std::cout << "\n";
}

void part_two() {
    std::ifstream MyReadFile("input.txt");

    std::string myText;

    std::vector<int> left_list;
    std::unordered_map<int, int> right_map;

    int similarity_score = 0;

    while (std::getline(MyReadFile, myText)) {

        int num = 0;

        for (int i = 0; i < myText.length(); i++) {

            if (isdigit(myText[i])) {

                 num = num * 10 + myText[i] - '0'; 

            } else {
                i += 2;
                left_list.push_back(num);
                num = 0;
            }
    
        }

        right_map[num]++;

    }

    for (int i = 0; i < left_list.size(); i++) {
        similarity_score += right_map[left_list[i]] * left_list[i];
    }

    std::cout << similarity_score;
    std::cout << "\n";
}

int main() {
    part_one();

    part_two();

    return 0;
}