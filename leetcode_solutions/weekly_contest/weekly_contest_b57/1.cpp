#include "utils.h"

class Solution {
public:
    //模拟题，数一遍就行
    bool areOccurrencesEqual(string s) {
        int count[26]={0};
        for(char c:s)count[c-'a']++;
        int num=*max_element(count,count+26);
        for(int a:count){
            if(a==0)continue;
            if(a==num)continue;
            return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abacbc";
    auto ans=sol.areOccurrencesEqual(s);
    DBG(ans);

    system("pause");
    return 0;
}
