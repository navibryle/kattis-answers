
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <tuple>
#include <math.h>
#include <sstream>

int main(){
    std::vector<std::string> input;
    std::string input_line;
    std::stringstream ss;
    while(std::cin) {
        std::getline(std::cin, input_line);
        input.push_back(input_line);
    }

    std::istringstream paramsInp(input[0]);
    std::vector<std::string> params;
    std::string someNum;
    std::vector<std::string> res{};
    unsigned numCards;
    unsigned pred;
    unsigned steps;
    unsigned count{0};
    while(std::getline(paramsInp,someNum,' ')){
        ss << someNum;
        if (count == 0){
            numCards = std::stoul(someNum);
        }else if (count ==1){
            pred = std::stoul(someNum);
        }else if (count == 3){
            steps = std::stoul(someNum);
        }
        count++;
    }

    for (unsigned idx = 1; idx < input.size();idx++){
        std::istringstream cards(input[idx]);
        std::string temp;
        bool isFirst{true};
        bool toKeep{false};
        while(std::getline(cards,temp,' ')){
            if (isFirst){
                isFirst = false;
                continue;
            }
            if (std::stoul(temp) == pred){
                toKeep = true;
            }

        }
        if (toKeep){
            std::cout << "KEEP" << std::endl;
        }else{
            std::cout << "REMOVE" << std::endl;
        }
        toKeep = false;
    }
    
}