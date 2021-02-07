#include "utils.h"

class Solution {
    void dfs(int curidx,int cursum,vi&nums,set<int>&S){
        if(curidx==nums.size()){
            S.insert(cursum);
        }
        else{
            //不取curidx下标对应值的dfs
            dfs(curidx+1,cursum,nums,S);
            //取curidx下标对应值的dfs
            dfs(curidx+1,cursum+nums[curidx],nums,S);
        }
    }
    //get_all_possible_sum()用来获取一个数组中所有数可能的子序列和
    //如果nums长度为n，那么可能的子序列和有2^n种（去重前）
    set<int>get_all_possible_sum(vi&nums){
        set<int>S;
        //回溯获取所有可能的值
        dfs(0,0,nums,S);
        return S;
    }
public:
    //本题如果要求40个数所能组合成的和，2^40肯定超出时间范围，所以拆解成两个2^20的问题
    int minAbsDifference(vector<int>& nums, int goal) {
        //如果goal==0，一个也不取和就是零
        if(goal==0)return 0;
        //如果goal>所有正数的和，直接出答案
        if(goal>0){
            int sum=0;
            for(int a:nums)if(a>0)sum+=a;
            if(sum<=goal)return goal-sum;
        }
        //如果goal<所有负数的和，直接出答案
        else{
            int sum=0;
            for(int a:nums)if(a<0)sum+=a;
            if(sum>=goal)return abs(goal-sum);
        }
        //half1表示数组前一半，half2表示数组后一半
        vector<int>half1,half2;
        half1.insert(half1.end(),nums.begin(),nums.begin()+nums.size()/2);
        half2.insert(half2.end(),nums.begin()+nums.size()/2,nums.end());
        auto all_possible_sum1=get_all_possible_sum(half1);
        //如果前一半能凑出goal直接返回零
        if(all_possible_sum1.count(goal))return 0;
        auto all_possible_sum2=get_all_possible_sum(half2);
        //如果后一半能凑出goal直接返回零
        if(all_possible_sum2.count(goal))return 0;
        int ans=INT_MAX;
        for(int a:all_possible_sum1){
            //b为a要凑goal的话，要凑的剩余部分
            int b=goal-a;
            //在all_possible_sum2中找和b最接近的值
            auto it=all_possible_sum2.lower_bound(b);
            if(it!=all_possible_sum2.end()){
                chmin(ans,*it-b);
            }
            if(it!=all_possible_sum2.begin()){
                chmin(ans,b-*prev(it));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{7,-9,15,-2};
    int goal=-5;
    auto ans=sol.minAbsDifference(nums,goal);
    DBG(ans);

    system("pause");
    return 0;
}
