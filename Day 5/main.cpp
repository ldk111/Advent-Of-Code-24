#include <iostream>
#include <fstream>
#include <vector>

void part_one() {
    std::ifstream MyReadFile("input.txt");

    std::string myText;
    int tot = 0;

    std::vector<std::vector<int>> order;

    while (std::getline(MyReadFile, myText)) {

        int numOne = 0;
        int numTwo = 0;

        i = 0; 

        while (isdigit(myText[i])) {
            numOne = numOne * 10 + myText[i] - '0';
            i += 1;
        }

        i += 1

        while (isdigit(myText[i])) {
            numTwo = numTwo * 10 + myText[i] - '0';
            i += 1;
        }
    }
    std::cout << tot;
    std::cout << "\n";
}

void part_two() {

}

int main() {
    part_one();
    part_two();
    return 0;
}