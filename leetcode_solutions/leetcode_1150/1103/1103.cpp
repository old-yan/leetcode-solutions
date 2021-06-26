#include "utils.h"

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        ll first_turn=num_people*(num_people+1)/2;
        ll turn=[&](){
            ll low=0,high=candies/num_people;
            while(low<high){
                ll mid=(low+high+1)/2;
                ll num=(first_turn+first_turn+(mid-1)*num_people*num_people)*mid/2;
                if(num<=candies)low=mid;
                else high=mid-1;
            }
            return low;
        }();
        ll rest=candies-(first_turn+first_turn+(turn-1)*num_people*num_people)*turn/2;
        vector<int> ans(num_people,0);
        for(ll i=0,j=num_people*turn+1;i<num_people;i++){
            ans[i]=(i*2+2+(turn-1)*num_people)*turn/2;
            if(rest>=0){
                ans[i]+=min(j,rest);
                rest-=j;
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int candies=7;
    int num_people=4;
    auto ans=sol.distributeCandies(candies,num_people);
    DBGV(ans);

    system("pause");
    return 0;
}
