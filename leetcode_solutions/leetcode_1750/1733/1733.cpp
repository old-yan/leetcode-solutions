#include "utils.h"

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size();
        bitset<500>B[m];
        REP(i,m){
            for(int a:languages[i]){
                B[i].set(a-1);
            }
        }
        int ans=INT_MAX;
        REP(i,n){
            bitset<500>need;
            for(auto&f:friendships){
                if((B[f[0]-1]&B[f[1]-1]).count()==0){
                    if(!B[f[0]-1][i])need.set(f[0]-1);
                    if(!B[f[1]-1][i])need.set(f[1]-1);
                }
            }
            chmin(ans,int(need.count()));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    vvi languages=makevvi("[[1],[2],[1,2]]");
    vvi friendships=makevvi("[[1,2],[1,3],[2,3]]");
    auto ans=sol.minimumTeachings(n,languages,friendships);
    DBG(ans);

    system("pause");
    return 0;
}
