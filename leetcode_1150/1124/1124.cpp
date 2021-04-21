#include "utils.h"

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        for(auto&h:hours){
            if(h>8)h=1;
            else h=-1;
        }
        partial_sum(ALL(hours),hours.begin());
        vector<pair<int,int>>v;
        v.emplace_back(0,-1);
        int ans=0;
        REP(i,hours.size()){
            int low=0,high=v.size();
            while(low<high){
                int mid=low+high>>1;
                if(v[mid].first<hours[i])high=mid;
                else low=mid+1;
            }
            if(low<v.size())chmax(ans,int(i-v[low].second));
            else v.emplace_back(hours[i],i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi hours{8,5,10,8,6,7,10,6};
    auto ans=sol.longestWPI(hours);
    DBG(ans);

    system("pause");
    return 0;
}
