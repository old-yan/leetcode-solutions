#include "utils.h"

class Solution {
    int n,can[16]={0},mask[16],len[16],ans=0;
    void dfs(int idx,int curmask,int curlen){
        if(idx==n)chmax(ans,curlen);
        else{
            if(can[idx]&&!(curmask&mask[idx]))dfs(idx+1,curmask|mask[idx],curlen+len[idx]);
            dfs(idx+1,curmask,curlen);
        }
    }
public:
    int maxLength(vector<string>& arr) {
        n=arr.size();
        REP(i,n){
            mask[i]=0;
            for(char c:arr[i])mask[i]|=1<<(c-'a');
            len[i]=arr[i].size();
            if(__builtin_popcount(mask[i])==len[i])can[i]=true;
        }
        dfs(0,0,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>arr{"cha","r","act","ers"};
    auto ans=sol.maxLength(arr);
    DBG(ans);

    system("pause");
    return 0;
}
