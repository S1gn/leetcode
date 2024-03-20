#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start = 0;
        int end = 0;
        int currentLength = 0;
        vector<string> result;
        for(int i=0; i<words.size(); i++)
        {
            if(currentLength + words[i].length() <= maxWidth)
            {
                end++;
                currentLength += words[i].length() + 1;
            }
            else{
                result.push_back(combine(words, start, end, maxWidth));
                start = end;
                currentLength = 0;
                i--;
            }
        }
        if(start<words.size())
        {
            string last = "";
            for(int i=start; i<words.size(); i++)
            {
                last += words[i];
                last += " ";
            }
            if(last.length() > maxWidth)
                last = last.substr(0, maxWidth);
            for(int i=last.length(); i<maxWidth; i++)
                last += " ";
            result.push_back(last);
        }
        return result;
    }

    string combine(vector<string> words, int start, int end, int width)
    {
        string result = "";
        vector<int> blanknum;
        int blanksum = 0;
        for(int i=start; i<end; i++)
        {
            blanksum += words[i].length();
            blanknum.push_back(0);
        }
        blanksum = width - blanksum;
        if((end - start) == 1)
        {
            result += words[start];
            for(int i=0; i<blanksum; i++)
            {
                result += " ";
            }
            return result;
        }
        blanknum.pop_back();
        while(blanksum>0)
        {
            for(int i=0; i<blanknum.size();i++)
            {
                blanknum[i]++;
                blanksum--;
                if(blanksum<=0)
                    break;
            }
        }
        for(int i=start; i<end; i++)
        {
            result = result + words[i];
            for(int j=0; j<blanknum[i - start]; j++)
                result = result + " ";
        }
        return result;
        
    }
};
int main() {
    vector<string> words = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
    Solution solution;
    for(string i: solution.fullJustify(words, 16))
        cout<<i<<endl;
    return 0;
}