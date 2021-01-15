#include "utils.h"

class Solution {
    multiset<int>S1,S2;
    void adjust(){
        if(S1.size()>S2.size()+1){
            S2.insert(*S1.rbegin());
            S1.erase(S1.find(*S1.rbegin()));
        }
        else if(S1.size()<S2.size()){
            S1.insert(*S2.begin());
            S2.erase(S2.begin());
        }
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>ans;
        for(int i=0,j=0;i+k<=nums.size();i++){
            while(j<i+k){
                if(S1.empty())S1.insert(nums[j]);
                else if(nums[j]>*S1.rbegin())S2.insert(nums[j]);
                else S1.insert(nums[j]);
                adjust();
                j++;
            }
            if(k%2)ans.pb(*S1.rbegin());
            else ans.pb((double(*S1.rbegin())+double(*S2.begin()))/2);
            if(S2.find(nums[i])!=S2.end())S2.erase(S2.find(nums[i]));
            else S1.erase(S1.find(nums[i]));
            adjust();
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,4,2,3};
    int k=4;
    auto ans=sol.medianSlidingWindow(nums,k);
    DBGV(ans);

    system("pause");
    return 0;
}
