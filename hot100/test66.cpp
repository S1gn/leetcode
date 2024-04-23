#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add = (1 + digits[digits.size() - 1])/10;
        digits[digits.size() - 1] = (digits[digits.size() - 1] + 1) % 10;
        int i = digits.size() - 2;
        while(add > 0 && i >= 0)
        {
            add = (1 + digits[i])/10;
            digits[i] = (digits[i] + 1) % 10;
            i--;
        }
        if(add > 0)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
        
    }
};
int main() {
    Solution solution;
    
    return 0;
}