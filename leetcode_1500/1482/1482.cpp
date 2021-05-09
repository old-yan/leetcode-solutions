#include "utils.h"

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(m*k>n)return -1;
        int low=1,high=*max_element(ALL(bloomDay));
        while(low<high){
            int mid=low+high>>1;
            int cnt=0;
            for(int left=0,right;left<bloomDay.size();){
                for(right=left;right<left+k&&right<bloomDay.size()&&bloomDay[right]<=mid;right++);
                if(right==left+k){
                    cnt++;
                    left=right;
                }
                else left=right+1;
            }
            if(cnt>=m)high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi bloomDay{1,10,3,10,2};
    int m=3;
    int k=1;
    auto ans=sol.minDays(bloomDay,m,k);
    DBG(ans);

    system("pause");
    return 0;
}
