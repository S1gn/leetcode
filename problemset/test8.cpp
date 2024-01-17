#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        int now_num = 0;
        int sign = 1;
        // 0还未开始计数， -1正在计负数， +1正在计正数
        int flag = 0;
        for(char c:s){
            if(flag == 0){
                if(c == ' ')continue;
                if(c == '-'){sign = -1; flag = 1;continue;}
                else if(c == '+'){sign = 1; flag = 1;continue;}
                else if(c >= '0' and c<= '9')flag = 1;
                else break;
            }
            if(flag == 1){
                if(c >= '0' and c<= '9'){
                    now_num = int(c - '0');
                    if(num_32(num, now_num, sign) == 0){
                        num = num * 10 + now_num;
                    }else if(num_32(num, now_num, sign) == 1){
                        return 2147483647;
                    }else if(num_32(num, now_num, sign) == -1){
                        return -2147483648;
                    }
                
                    
                }else{
                    break;
                }
            }
                
        }
        return num * sign;
    }
    // a: num, b: now_num
    // sign = 1 (2147483647 - now_num)/10>a
    // sign = -1 (2147483648 - now_num)/10>a
    int num_32(int a, int b, int sign){
        if(sign == 1){
            if((double((2147483647 - b))/10)>a)return 0;
            else return 1;

        }else{
            if((double((2147483648 - b))/10)>a)return 0;
            else return -1;
        }
    }
};


int main() {
    Solution solution;
    string s = "-422";
    cout << solution.myAtoi(s) << endl;
    return 0;
}