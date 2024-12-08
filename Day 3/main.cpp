#include <iostream>
#include <fstream>

void part_one() {
    std::ifstream MyReadFile("input.txt");

    std::string myText;
    int tot = 0;

    while (std::getline(MyReadFile, myText)) {

        for (int i = 0; i < myText.length(); i++) {

            // check prefix
            if (myText[i] == 'm' && myText[i+1] == 'u' && myText [i+2] == 'l' && myText[i+3] == '(') {

                i += 4;
                
                // check num 1
                int numOne = 0;

                int maxLen = 3;

                while (isdigit(myText[i]) && maxLen > 0) {
                    numOne = numOne * 10 + myText[i] - '0';
                    maxLen -= 1;
                    i += 1;
                }

                // check comma
                if (myText[i] == ',') {

                    i += 1;

                    // check num 2
                    int numTwo = 0;

                    maxLen = 3;

                    while (isdigit(myText[i])) {
                        numTwo = numTwo * 10 + myText[i] - '0';
                        maxLen -= 1;
                        i += 1;
                    }

                    // check suffix
                    if (myText[i] == ')') {
                        tot += numOne * numTwo;
                    }

                }
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
    bool doOn = true;

    while (std::getline(MyReadFile, myText)) {

        for (int i = 0; i < myText.length(); i++) {

            if (doOn) {
                
                // check prefix
                if (myText[i] == 'm' && myText[i+1] == 'u' && myText [i+2] == 'l' && myText[i+3] == '(') {
 
                    i += 4;
                    
                    // check num 1
                    int numOne = 0;

                    int maxLen = 3;

                    while (isdigit(myText[i]) && maxLen > 0) {
                        numOne = numOne * 10 + myText[i] - '0';
                        maxLen -= 1;
                        i += 1;
                    }

                    // check comma
                    if (myText[i] == ',') {

                        i += 1;

                        // check num 2
                        int numTwo = 0;

                        maxLen = 3;

                        while (isdigit(myText[i])) {
                            numTwo = numTwo * 10 + myText[i] - '0';
                            maxLen -= 1;
                            i += 1;
                        }

                        // check suffix
                        if (myText[i] == ')') {
                            tot += numOne * numTwo;
                        }
                    }
                }
            }

            // check do
            if (myText[i] == 'd' && myText[i+1] == 'o') {
                i += 2;

                // check don't
                if (myText[i] == 'n' && myText[i+1] == '\'' && myText[i+2] == 't' && myText[i+3] == '(' && myText[i+4] == ')') {
                    i += 4;
                    doOn = false;
                } else if (myText[i] == '(' && myText[i+1] == ')') {
                    i += 1;
                    doOn = true;
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