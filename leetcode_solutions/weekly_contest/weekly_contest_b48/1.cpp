#include "utils.h"

class Solution {
public:
    //遍历全部字符，将所有的数字字符排序去重
    int secondHighest(string s) {
        set<int>S;
        for(char c:s){
            if(isdigit(c)){
                S.insert(c-'0');
            }
        }
        if(S.size()<2)return -1;
        else return *prev(prev(S.end()));
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
