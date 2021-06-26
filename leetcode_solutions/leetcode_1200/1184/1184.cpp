#include "utils.h"

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum=accumulate(ALL(distance),0);
        if(start>destination)swap(start,destination);
        int cur=accumulate(distance.begin()+start,distance.begin()+destination,0);
        return min(cur,sum-cur);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi distance{1,2,3,4};
    int start=0;
    int destination=1;
    auto ans=sol.distanceBetweenBusStops(distance,start,destination);
    DBG(ans);

    system("pause");
    return 0;
}
