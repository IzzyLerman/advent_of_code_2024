#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>


int is_safe(int prev, int curr, int change){
    int diff = curr-prev;
    if(diff == 0){
        return 0;
    }
    int new_change = diff/std::abs(diff);
    
    if(change != 0 && change != new_change){
        return 0;
    }
    if(std::abs(diff) > 3){
        return 0;
    }
    return new_change;
}

bool report_is_safe(int st, int end, std::vector<int> v, int sk,int n){
    int skipped = sk;
    int change = 0;
    bool safe = true;
    int new_change;
    for(int i = st; i < end - 1; i++){
        if(false){
            std::cout << v[i] << " " << v[i+1] << " " << change << std::endl;
        }
        new_change = is_safe(v[i],v[i+1],change);
        //std::cout << new_change << std::endl;
        if(new_change == 0){
            //std::cout << v[i] << " " << v[i+1] << " " << change << std::endl;
            if (skipped> 0){
                return false;
            }else{
                skipped++;
                if(i == st || i == end - 2){
                }else{
                    new_change = is_safe(v[i-1],v[i+1],change);
                    if (new_change==0){
                        return false;
                    }else{
                        change = new_change;
                    }
                }
            }
        }else{
            change = new_change;
        }
    
    }
    return safe;
}

int main(){
    std::ifstream in;
    std::istringstream ss;
    std::string report;
    std::vector<int> v;
    int prev, curr, change = 0,new_change, diff = 0;
    int skipped;
    bool safe_a,safe_b,safe_c,safe;
    int tot = 0, n = 0;
    in.open("inp.txt");
    while(std::getline(in,report)){
        n++;
        v.clear();
        
        ss.clear();
        ss.str(report);
        while(ss >> curr){
            v.push_back(curr);
        }
        safe_a = report_is_safe(0,v.size(),v,0,n);
        safe_b = report_is_safe(1,v.size(),v,1,n);  
        safe_c = report_is_safe(0,v.size()-1,v,1,n);
        safe = safe_a||safe_b||safe_c;

        tot += safe?1:0;
        if(n>900){
            std::cout << safe_a << safe_b << safe_c <<safe<< std::endl;
            std::cout << n << ": " << report << "\tSafe?:" << safe <<std::endl;
        }
    }
    std::cout << tot << std::endl;
    return 0;
}