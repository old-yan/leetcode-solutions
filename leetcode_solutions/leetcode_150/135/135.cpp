#include "utils.h"

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int goup[n],godown[n];
        goup[0]=0;
        FOR(i,1,n){
            if(ratings[i]>ratings[i-1]){
                goup[i]=goup[i-1]+1;
            }
            else goup[i]=0;
        }
        godown[n-1]=0;
        FORR(i,n-2,0){
            if(ratings[i]>ratings[i+1]){
                godown[i]=godown[i+1]+1;
            }
            else godown[i]=0;
        }
        int ans=0;
        REP(i,n){
            ans+=1+max(goup[i],godown[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi ratings{1,2,2};
    auto ans=sol.candy(ratings);
    DBG(ans);

    system("pause");
    return 0;
}
