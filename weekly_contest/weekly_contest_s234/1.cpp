#include "utils.h"

class Solution {
public:
    //使用哈希表，对每段连续的数字字符串进行判重
    int numDifferentIntegers(string word) {
        unordered_set<string>S;
        for(int i=0;i<word.size();i++){
            if(isdigit(word[i])){
                string s;
                //忽略前缀零
                while(isdigit(word[i])){
                    if(s.size()||word[i]!='0')s+=word[i];
                    i++;
                }
                if(s.empty())s="0";
                S.insert(s);
            }
        }
        return S.size();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word="leet1234code234";
    auto ans=sol.numDifferentIntegers(word);
    DBG(ans);

    system("pause");
    return 0;
}
