#include "utils.h"
#include <sstream>

class Solution {
public:
    //使用字符串流，将 s 变成类似 cin 的东西，然后读取字符串，这样就可以方便地去掉空格
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string t;
        vector<int>v;
        while(ss>>t){
            if(isdigit(t[0])){
                v.push_back(stoi(t));
            }
        }
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1])return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s";
    auto ans=sol.areNumbersAscending(s);
    DBG(ans);

    system("pause");
    return 0;
}