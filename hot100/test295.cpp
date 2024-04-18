#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool cmp(const int a, const int b)
    {
        return a < b;
    }
class MedianFinder {
    private:
    priority_queue<int> minnums;
    priority_queue<int, vector<int>, greater<int>>maxnums;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (minnums.empty() || num <= minnums.top()) {
            minnums.push(num);
            if (maxnums.size() + 1 < minnums.size()) {
                maxnums.push(minnums.top());
                minnums.pop();
            }
        } else {
            maxnums.push(num);
            if (maxnums.size() > minnums.size()) {
                minnums.push(maxnums.top());
                maxnums.pop();
            }
        }
    }
    
    double findMedian() {
        if((maxnums.size() + minnums.size()) % 2 == 0)
        {
            cout<<maxnums.size() + minnums.size()<<minnums.top()<<maxnums.top()<<endl;
            return (double(minnums.top()) + double(maxnums.top()))/2.0;
        }
        else
            return (minnums.top());
    }
};
int main() {
    // Solution solution;
    MedianFinder a;
    a.addNum(-1);
    cout<<a.findMedian()<<endl;
    a.addNum(-2);
    cout<<a.findMedian()<<endl;
    a.addNum(-3);
    cout<<a.findMedian()<<endl;
    a.addNum(-4);
    cout<<a.findMedian()<<endl;
    a.addNum(-5);
    cout<<a.findMedian()<<endl;
    return 0;
}