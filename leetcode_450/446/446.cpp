#include "utils.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans=0;
        unordered_map<ll,int>getid;
        REP(i,A.size()){
            if(!getid.count(A[i])){
                getid[A[i]]=getid.size();
            }
        }
        unordered_map<ll,int>target[getid.size()];
        REP(i,A.size()){
            cout<<ans;
            for(auto&it:target[getid[A[i]]]){
                ans+=it.second;
                ll next=(ll)A[i]*2-it.first;
                if(getid.count(next)){
                    target[getid[next]][A[i]]+=it.second;
                }
            }
            REP(j,i){
                ll next=(ll)A[i]*2-A[j];
                if(getid.count(next)){
                    target[getid[next]][A[i]]++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{2,4,6,8,10};
    auto ans=sol.numberOfArithmeticSlices(A);
    DBG(ans);

    system("pause");
    return 0;
}
