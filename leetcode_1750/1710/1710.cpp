#include "utils.h"

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>>Q;
        for(auto&box:boxTypes){
            Q.emplace(box[1],box[0]);
        }
        int ans=0;
        while(truckSize>0){
            if(Q.empty())break;
            auto [a,b]=Q.top();
            Q.pop();
            ans+=a*min(b,truckSize);
            truckSize-=b;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi boxTypes=makevvi("[[1,3],[2,2],[3,1]]");
    int truckSize=4;
    auto ans=sol.maximumUnits(boxTypes,truckSize);
    DBG(ans);

    system("pause");
    return 0;
}
