#include "utils.h"

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int cnt[100001]={0};
        unordered_map<int,int>M;
        for(int a:nums)cnt[a]++;
        FOR(i,1,100001){
            if(cnt[i]){
                M[cnt[i]]++;
            }
        }
        REPR(i,nums.size()-1){
            if(M.size()==2){
                auto it=M.begin();
                auto it2=next(it);
                if(it->second==1&&(it->first==1||it->first==it2->first+1)){
                    return i+1;
                }
                if(it2->second==1&&(it2->first==1||it2->first==it->first+1)){
                    return i+1;
                }
            }
            else if(M.size()==1){
                auto it=M.begin();
                if(it->first==1||it->second==1)return i+1;
            }
            if(!--M[cnt[nums[i]]])M.erase(cnt[nums[i]]);
            if(--cnt[nums[i]])M[cnt[nums[i]]]++;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{10,2,8,9,3,8,1,5,2,3,7,6};
    auto ans=sol.maxEqualFreq(nums);
    DBG(ans);

    system("pause");
    return 0;
}
