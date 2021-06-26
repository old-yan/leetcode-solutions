#include "utils.h"

class Solution {
    int cnt[20001]={0};
public:
    int bestRotation(vector<int>& A) {
        REP(i,A.size()){
            if(i<A[i]){
                cnt[i+1]++;
                cnt[i+A.size()-A[i]+1]--;
            }
            else{
                cnt[0]++;
                cnt[i-A[i]+1]--;
                cnt[i+1]++;
                cnt[A.size()]--;
            }
        }
        int ans=0;
        FOR(i,1,A.size()){
            cnt[i]+=cnt[i-1];
            if(cnt[i]>cnt[ans]){
                ans=i;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{2,3,1,4,0};
    auto ans=sol.bestRotation(A);
    DBG(ans);

    system("pause");
    return 0;
}
