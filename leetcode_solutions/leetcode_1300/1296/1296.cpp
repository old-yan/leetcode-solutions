#include "utils.h"

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int>M;
        for(int a:nums)M[a]++;
        while(M.size()){
            map<int,int>::iterator it[k];
            it[0]=M.begin();
            FOR(i,1,k){
                it[i]=next(it[i-1]);
                if(it[i]==M.end()||it[i]->first!=it[i-1]->first+1)return false;
            }
            REPR(i,k-1){
                if(!--it[i]->second)M.erase(it[i]);
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,2,1,2,3,4,3,4,5,9,10,11};
    int k=3;
    auto ans=sol.isPossibleDivide(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
