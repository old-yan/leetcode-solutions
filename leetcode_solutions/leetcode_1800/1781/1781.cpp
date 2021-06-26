#include "Heap.h"
#include "utils.h"

class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        REP(i,n){
            int cnt[26]={0};
            BiHeap<int>maxH([&](int x,int y){return cnt[x]<cnt[y];});
            BiHeap<int>minH([&](int x,int y){return cnt[x]>cnt[y];});
            FOR(j,i,n){
                cnt[s[j]-'a']++;
                maxH.push(s[j]-'a');
                minH.push(s[j]-'a');
                minH.sink(s[j]-'a');
                int a=maxH.top(),b=minH.top();
                ans+=cnt[a]-cnt[b];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aabcb";
    auto ans=sol.beautySum(s);
    DBG(ans);

    system("pause");
    return 0;
}
