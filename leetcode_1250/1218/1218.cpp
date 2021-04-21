#include "utils.h"

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>M,M2;
        int ans=0;
        for(int a:arr)M[a]++;
        for(int a:arr){
            int num=M2.count(a)?M2[a]:1;
            chmax(ans,num);
            if(!--M[a])M.erase(a);
            if(M.count(a+difference)){
                chmax(M2[a+difference],num+1);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,5,7,8,5,3,4,2,1};
    int difference=-2;
    auto ans=sol.longestSubsequence(arr,dif);
    DBG(ans);

    system("pause");
    return 0;
}
