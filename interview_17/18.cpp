#include "utils.h"

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        unordered_map<int,int>M;
        for(int a:small)M[a]++;
        int oknum=0;
        pair<int,int>ans{INT_MAX,INT_MAX};
        for(int left=0,right=0;right<=big.size();right++){
            while(oknum==M.size()&&(!M.count(big[left])||M[big[left]]<0)){
                if(M.count(big[left]))M[big[left]]++;
                left++;
            }
            if(oknum==M.size())chmin(ans,make_pair(right-left,left));
            if(right<big.size()&&M.count(big[right])){
                if(!--M[big[right]])oknum++;
            }
        }
        if(ans.first==INT_MAX)
            return {};
        else
            return {ans.second,ans.second+ans.first-1};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi big{7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7};
    vi small{1,5,9};
    auto ans=sol.shortestSeq(big,small);
    DBGV(ans);

    system("pause");
    return 0;
}
