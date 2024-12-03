#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>


int mul_frag(std::string frag){
    if (frag.substr(0,4) != "mul("){
        return 0;
    }
    std::string tmp_n = "";
    std::string::const_iterator it = frag.begin()+4;
    while (it != frag.end() && std::isdigit(*it)){
        tmp_n += *it;
        ++it;
    }
    int a = std::stoi(tmp_n);
    if(it == frag.end()){
        return 0;
    }
    if(*it != ','){
        return 0;
    }
    ++it;
    tmp_n = "";
    while (it != frag.end() && std::isdigit(*it)){
        tmp_n += *it;
        ++it;
    }
    int b = std::stoi(tmp_n);
    if(*it != ')'){
        return 0;
    }
    if(it == frag.end()){
        return 0;
    }
    return a*b;
}
int do_or_nah(std::string frag){
    if (frag == "do()"){
        return 1;
    }else if(frag == "don't()"){
        return -1;
    }
    return 0;
}

int sol(int part){
    std::ifstream f("inp.txt");
    char c;
    std::string frag = "";
    bool reading = false;
    int tot = 0;
    bool en = true;
    while (f.get(c)){
        if(c == 'm'||c == 'd'){
            frag = "";
            reading = true;
        }
        if (reading){
            frag += c;
        }
        if(c == ')'){
            
            int tmp = mul_frag(frag);
            int tmp_2 = do_or_nah(frag);
            if(tmp_2!= 0){
                en = tmp_2 == 1;
            }
            if(part == 2){
                tmp *= en?1:0;
            }
            if(false){
                std::cout << tmp << std::endl;
                std::cout << frag << std::endl;
            }
            tot += tmp;
            reading = false;
            frag = "";
        }
    }
    return tot;
}

int main(){
    std::cout << sol(1) << std::endl;
    std::cout << sol(2) << std::endl;
    return 0;
}