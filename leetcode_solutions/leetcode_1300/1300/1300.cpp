#include "SegTree.h"
#include "utils.h"

SegTree<int>T1(100001,[](int x,int y){return x+y;});
SegTree<int>T2(100001,[](int x,int y){return x+y;});
class Solution {
    int getSum(int threshold){
        return T2(0,threshold)+T1(threshold+1,100000)*threshold;
    }
public:
    int findBestValue(vector<int>& arr, int target) {
        T1.set(0),T2.set(0);
        for(int a:arr){
            T1.step_forward(a);
            T2.step(a,a);
        }
        int Max=*max_element(ALL(arr));
        auto lowerbound=[&](){
            int low=1,high=Max;
            while(low<high){
                int mid=low+high>>1;
                if(getSum(mid)>=target)high=mid;
                else low=mid+1;
            }
            return low;
        }();
        int dis=abs(getSum(lowerbound)-target);
        int dis2=abs(getSum(lowerbound-1)-target);
        if(dis<dis2)return lowerbound;
        else return lowerbound-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{2,3,5};
    int target=11;
    auto ans=sol.findBestValue(arr,target);
    DBG(ans);

    system("pause");
    return 0;
}
