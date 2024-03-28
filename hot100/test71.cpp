#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathlist;
        stack<string> templist;
        string now = "";
        
        for(char c:path)
        {
            if(c == '/')
            {
                if(now.length() == 0)
                    continue;
                else
                {
                    if(now == ".")
                    {
                        now = "";
                        continue;
                    }
                        
                    else if(now == ".." && pathlist.size() != 0)
                    {
                        now = "";
                        pathlist.pop();
                    }   
                    else if(now == ".." && pathlist.size() == 0)
                    {
                        now = "";
                        continue;
                    }
                    else
                        pathlist.push(now);
                    
                    now = "";
                }
            }
            else
                now += c;
        }
        
        if(now.length() == 0);
        else
        {
            if(now == ".")
            {
                now = "";
            }
                
            else if(now == ".." && pathlist.size() != 0)
            {
                now = "";
                pathlist.pop();
            }   
            else if(now == ".." && pathlist.size() == 0)
            {
                now = "";
            }
            else
                pathlist.push(now);
            
            now = "";
        }
        string result="";
        if(pathlist.empty())
            return "/";
        while(!pathlist.empty())
        {
            templist.push(pathlist.top());
            pathlist.pop();
        }
        while(!templist.empty())
        {
            result += '/';
            result += templist.top();
            templist.pop();
        }
        return result;

    }
};
int main() {
    Solution solution;
    cout<<solution.simplifyPath("/../");
    return 0;
}