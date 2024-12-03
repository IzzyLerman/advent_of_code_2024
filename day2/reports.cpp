#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>


int main(){
    std::ifstream in;
    std::istringstream ss;
    std::string report;
    std::vector<int> v;
    int prev, curr, change,new_change, diff = 0;
    bool safe;
    int tot = 0, n = 0;
    in.open("inp.txt");
    for(int i = 0; i < 1000; i++){
        std::getline(in,report);
        n++;
        change = 0;
        safe = true;
        ss.str(report);
        ss.clear();
        ss>>prev;
        while(ss >> curr){
            diff = curr-prev;
            if(diff == 0){
                safe = false;
            }else{
                new_change = diff/std::abs(diff);
                std::cout << diff << std::endl;
            }
            if(change != 0 && change != new_change){
                safe = false;
            }
            if(std::abs(diff) > 3){
                safe = false;
            }
            change = new_change;
            prev = curr;
        }
        std::cout << "Report " << n << ": Safe? " << safe << std::endl;
        //std::cout << report << std::endl;
        tot += safe?1:0;
    }
    std::cout  << tot << std::endl;
    return 0;
}