#include "utils.h"

class Solution {
    int f(string&s){
        char c=*min_element(ALL(s));
        int num=0;
        for(char d:s)if(c==d)num++;
        return num;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int cnt[12]={0};
        for(string&w:words){
            cnt[f(w)]++;
        }
        vi ans;
        for(auto&q:queries){
            ans.pb(accumulate(cnt+f(q)+1,cnt+12,0));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>queries{
        "bbb","cc"
    };
    vector<string>words{
        "a","aa","aaa","aaaa"
    };
    auto ans=sol.numSmallerByFrequency(queries,words);
    DBGV(ans);

    system("pause");
    return 0;
}
