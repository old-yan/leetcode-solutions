#include "utils.h"

class Solution {
    unordered_map<string,int>M;
    void init(){
        string months[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        REP(i,12)M[months[i]]=i+1;
    }
public:
    string reformatDate(string date) {
        init();
        string ans;
        auto v=split(date);
        ans+=v[2];
        ans+=" ";
        int month=M[v[1]];
        ans+=month<10?"0"+i2s(month):i2s(month);
        ans+=" ";
        while(!isdigit(v[0].back()))v[0].pop_back();
        ans+=v[0].size()==1?" "+v[0]:v[0];
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string date="20th Oct 2052";
    auto ans=sol.reformatDate(date);
    DBG(ans);

    system("pause");
    return 0;
}
