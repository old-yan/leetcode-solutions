#include "utils.h"

class Solution {
    struct Minheap{
        ll sum=0;
        priority_queue<int,vi,greater<int>>Q;
        void push(int val){sum+=val,Q.push(val);}
        void pop(){sum-=Q.top(),Q.pop();}
        int top(){return Q.top();}
    }Q1;
    struct Maxheap{
        ll sum=0;
        priority_queue<int>Q;
        void push(int val){sum+=val,Q.push(val);}
        void pop(){sum-=Q.top(),Q.pop();}
        int top(){return Q.top();}
    }Q2;
public:
    vector<int> numsGame(vector<int>& nums) {
        int n=nums.size();
        vi ans(n);
        REP(i,n){
            int a=nums[i]+n-i;
            if(i%2){
                Q1.push(a);
                Q2.push(Q1.top());
                Q1.pop();
            }
            else{
                Q2.push(a);
                Q1.push(Q2.top());
                Q2.pop();
            }
            ll t=Q1.top();
            ans[i]=((Q1.sum-t*(i/2+1))+(t*((i+1)/2)-Q2.sum))%MOD;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,4,5,1,6,7};
    auto ans=sol.numsGame(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
