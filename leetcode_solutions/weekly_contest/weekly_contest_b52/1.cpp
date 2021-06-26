#include "utils.h"

class Solution {
public:
    //将单词按空格切割后，获取其真实位置
    string sortSentence(string s) {
        //切割，v是子串列表
        auto v=split(s,' ');
        //获取每个子串的后缀数字所代表的真实下标
        vi idxes(v.size());
        REP(i,v.size()){
            idxes[i]=v[i].back()-'0'-1;
            v[i].pop_back();
        }
        //按照真实下标，将v中的子串送到目的地
        vector<string>v2(v.size());
        REP(i,v.size()){
            v2[idxes[i]]=v[i];
        }
        auto ans=v2[0];
        FOR(i,1,v2.size()){
            ans+=" "+v2[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="is2 sentence4 This1 a3";
    auto ans=sol.sortSentence(s);
    DBG(ans);

    system("pause");
    return 0;
}
