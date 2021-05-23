#include "utils.h"

class Solution {
public:
    int secondHighest(string s) {
        set<char>S;
        for(char c:s){
            if(isdigit(c)){
                S.insert(c);
            }
        }
        if(S.size()<2)return -1;
        else return *prev(prev(S.end()))-'0';
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="dfa12321afd";
    auto ans=sol.secondHighest(s);
    DBG(ans);

    system("pause");
    return 0;
}
