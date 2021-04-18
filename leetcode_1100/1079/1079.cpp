#include "utils.h"

class Solution {
    int cnt[26]={0};
    int ans=0;
    void dfs(int cur,vi&v){
        if(cur==26){
            int res=factorial(accumulate(ALL(v),0));
            for(int a:v)res/=factorial(a);
            ans+=res;
        }
        else{
            dfs(cur+1,v);
            FOR(i,1,cnt[cur]+1){
                v.pb(i);
                dfs(cur+1,v);
                v.pop_back();
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        for(char c:tiles)cnt[c-'A']++;
        vi v;
        dfs(0,v);
        return ans-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string tiles="AAABBC";
    auto ans=sol.numTilePossibilities(tiles);
    DBG(ans);

    system("pause");
    return 0;
}
