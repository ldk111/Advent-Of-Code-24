#include <iostream>
#include <fstream>
#include <vector>

int search(std::vector<std::vector<char>> wordSearch, int x1, int x2, int x3, int y1, int y2, int y3) {
    if (wordSearch[y1][x1] == 'M' && wordSearch[y2][x2] == 'A' && wordSearch[y3][x3] == 'S') {
        return 1; 
    } else {
        return 0;
    }
}

int left(std::vector<std::vector<char>> wordSearch, int x, int y) {
    return search(wordSearch, x-1, x-2, x-3, y, y, y);
}

int right(std::vector<std::vector<char>> wordSearch, int x, int y) {
    return search(wordSearch, x+1, x+2, x+3, y, y, y);
}

int up(std::vector<std::vector<char>> wordSearch, int x, int y) {
    return search(wordSearch, x, x, x, y-1, y-2, y-3);
}

int down(std::vector<std::vector<char>> wordSearch, int x, int y) {
    return search(wordSearch, x, x, x, y+1, y+2, y+3);
}

int diag_up_right(std::vector<std::vector<char>> wordSearch, int x, int y) {
    return search(wordSearch, x+1, x+2, x+3, y-1, y-2, y-3);
}

int diag_up_left(std::vector<std::vector<char>> wordSearch, int x, int y) {
    return search(wordSearch, x-1, x-2, x-3, y-1, y-2, y-3);
}

int diag_down_left(std::vector<std::vector<char>> wordSearch, int x, int y) {
    return search(wordSearch, x-1, x-2, x-3, y+1, y+2, y+3);
}

int diag_down_right(std::vector<std::vector<char>> wordSearch, int x, int y) {
    return search(wordSearch, x+1, x+2, x+3, y+1, y+2, y+3);
}

void part_one() {
    std::ifstream MyReadFile("input.txt");

    std::string myText;

    std::vector<std::vector<char>> wordSearch;
    int tot = 0;

    while (std::getline(MyReadFile, myText)) {

        std::vector<char> line; 

        for (int i = 0; i < myText.length(); i++) {
            line.push_back(myText[i]);
            
        }
        wordSearch.push_back(line);
    }

    for (int y = 0; y < wordSearch.size(); y++) {
        for (int x = 0; x < wordSearch[y].size(); x++) {
            if (wordSearch[y][x] == 'X') {
                if (x > 2) tot += left(wordSearch, x, y);
                if (x < wordSearch[y].size() - 3) tot += right(wordSearch, x, y);
                if (y > 2) tot += up(wordSearch, x, y);
                if (y < wordSearch.size() - 3) tot += down(wordSearch, x, y);
                if (x > 2 && y > 2) tot += diag_up_left(wordSearch, x, y);
                if (x < wordSearch[y].size() - 3 && y > 2) tot += diag_up_right(wordSearch, x, y);
                if (x > 2 && y < wordSearch.size() - 3) tot += diag_down_left(wordSearch, x, y);
                if (x < wordSearch[y].size() - 3 && y < wordSearch.size() - 3) tot += diag_down_right(wordSearch, x, y);
            }
        }
    }
    std::cout << tot;
    std::cout << "\n";
}

// m.m,.a.,s.s
int masOne(std::vector<std::vector<char>> wordSearch, int x, int y) {
    if (wordSearch[y-1][x-1] == 'M' && wordSearch[y-1][x+1] == 'M' && wordSearch[y+1][x-1] == 'S' && wordSearch[y+1][x+1] == 'S') {
        return 1;
    }
    return 0;
}

// s.m,.a.,s.m
int masTwo(std::vector<std::vector<char>> wordSearch, int x, int y) {
    if (wordSearch[y-1][x-1] == 'S' && wordSearch[y-1][x+1] == 'M' && wordSearch[y+1][x-1] == 'S' && wordSearch[y+1][x+1] == 'M') {
        return 1;
    }
    return 0;
}

// s.s,.a.,m.m
int masThree(std::vector<std::vector<char>> wordSearch, int x, int y) {
    if (wordSearch[y-1][x-1] == 'S' && wordSearch[y-1][x+1] == 'S' && wordSearch[y+1][x-1] == 'M' && wordSearch[y+1][x+1] == 'M') {
        return 1;
    }
    return 0;
}

// m.s,.a.,m.s
int masFour(std::vector<std::vector<char>> wordSearch, int x, int y) {
    if (wordSearch[y-1][x-1] == 'M' && wordSearch[y-1][x+1] == 'S' && wordSearch[y+1][x-1] == 'M' && wordSearch[y+1][x+1] == 'S') {
        return 1;
    }
    return 0;
}


void part_two() {
    std::ifstream MyReadFile("input.txt");

    std::string myText;

    std::vector<std::vector<char>> wordSearch;
    int tot = 0;

    while (std::getline(MyReadFile, myText)) {

        std::vector<char> line; 

        for (int i = 0; i < myText.length(); i++) {
            line.push_back(myText[i]);
            
        }
        wordSearch.push_back(line);
    }

    for (int y = 0; y < wordSearch.size(); y++) {
        for (int x = 0; x < wordSearch[y].size(); x++) {
            if (wordSearch[y][x] == 'A') {
                if (x > 0 && y > 0 && x < wordSearch[y].size() - 1 && y < wordSearch.size() - 1) {
                    tot += masOne(wordSearch, x, y);
                    tot += masTwo(wordSearch, x, y);
                    tot += masThree(wordSearch, x, y);
                    tot += masFour(wordSearch, x, y);
                }
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


