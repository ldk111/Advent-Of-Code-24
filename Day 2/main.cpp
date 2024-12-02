#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void part_one() {
    std::ifstream MyReadFile("input.txt");

    std::string myText;

    int tot = 0;

    while (std::getline(MyReadFile, myText)) {

        int prev_num = -1;
        int curr_num = 0;
        bool start = true;
        bool ascending = false;
        bool descending = false;

        for (int i = 0; i < myText.length(); i++) {

            if (isdigit(myText[i])) {
                curr_num = curr_num * 10 + myText[i] - '0'; 
            }
            if ((!isdigit(myText[i])) || (i == myText.length() - 1)) {

                if (prev_num != -1) {

                    if (start == true) {
                        if (curr_num - prev_num > 0) {
                            ascending = true;
                        } else {
                            descending = true;
                        }
                        start = false;
                    }

                    if (ascending) {
                        if (curr_num - prev_num < 0) {
                            break;
                        }
                    }

                    if (descending) {
                        if (curr_num - prev_num > 0) {
                            break;
                        }
                    }

                    if (std::abs(curr_num - prev_num) > 0 && std::abs(curr_num - prev_num) < 4) {
                        if (i == myText.length() - 1) {
                            tot += 1;
                        }
                    } else {
                        break;
                    }
                }

                prev_num = curr_num;
                curr_num = 0;
            }
        }
    }

    std::cout << tot;
    std::cout << "\n";

}

void part_two() {
    std::ifstream MyReadFile("input.txt");

    std::string myText;

    int tot = 0;

    while (std::getline(MyReadFile, myText)) {

        std::vector<int> line = {};

        int curr_num = 0;
        int prev_num = 0;
        
        for (int i = 0; i < myText.length(); i++) {

            if (isdigit(myText[i])) {
                curr_num = curr_num * 10 + myText[i] - '0'; 
            }
            if ((!isdigit(myText[i])) || (i == myText.length() - 1)) {
                line.push_back(curr_num);
                curr_num = 0;
            }
        
        }

        for (int j = 0; j < line.size(); j++) {

            std::vector<int> temp_line = line;

            temp_line.erase(temp_line.begin() + j);

            bool start = true;
            bool ascending = false;
            bool descending = false;
            bool valid = false;
            
            for (int i = 1; i < temp_line.size(); i++) {

                curr_num = temp_line[i];
                prev_num = temp_line[i - 1];

                if (start == true) {
                    if (curr_num - prev_num > 0) {
                        ascending = true;
                    } else {
                        descending = true;
                    }
                    start = false;
                }

                if (ascending) {
                    if (curr_num - prev_num < 0) {
                        break;
                    }
                }

                if (descending) {
                    if (curr_num - prev_num > 0) {
                        break;
                    }
                }

                if (std::abs(curr_num - prev_num) > 0 && std::abs(curr_num - prev_num) < 4) {
                    if (i == temp_line.size() - 1) {
                        valid = true;
                        break;
                    }
                } else {
                    break;
                }
            }

            if (valid) {
                tot += 1;
                break;
            }
        }
    }

    std::cout << tot;
    std::cout << "\n";

}

int main() {
    part_one();

    part_two();

    return 0;
}