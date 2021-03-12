#include "utils.h"

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vi next=next_different(seats);
        int ans=0;
        for(int i=seats[0]?next[0]:0;;){
            if(!i)chmax(ans,next[i]);
            else if(next[i]==seats.size())chmax(ans,next[i]-i);
            else chmax(ans,(next[i]-i+1)/2);
            i=next[i];
            if(i==seats.size())break;
            i=next[i];
            if(i==seats.size())break;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi seats{1,0,0,0,1,0,1};
    auto ans=sol.maxDistToClosest(seats);
    DBG(ans);

    system("pause");
    return 0;
}
