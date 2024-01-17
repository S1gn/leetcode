#include <iostream>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        int binary[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string sign[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result;
        int now_num = 0;
        while(num > 0){
            now_num = lastover(num, binary);
            result = result.append(sign[now_num]);
            num = num - binary[now_num];
        }
        return result;

    }

    int lastover(int num, int* binary){
        for(int i = 0; i < 13; i++){
            if(num >= binary[i]){
                return i;
            }
        }
    }
};
int main() {
    Solution solution;
    int i = 1994;
    cout<<solution.intToRoman(i);
    return 0;
}