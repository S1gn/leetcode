#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while(i<n)
        {
            int sumgas = 0, sumcost = 0;
            int gasnum = 0;
            while(gasnum < n)
            {
                int j =  (i + gasnum) % n;
                sumgas += gas[j];
                sumcost += cost[j];
                if (sumcost > sumgas) {
                    break;
                }
                gasnum++;
            }
            if(gasnum == n)
                return i;
            else
            {
                i = gasnum + i + 1;
            }
        }
        return -1;
    }
};
int main() {
    Solution solution;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout<<solution.canCompleteCircuit(gas, cost);
    return 0;
}