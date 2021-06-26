#include "utils.h"

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(ALL(people),greater<int>());
        int ans=0;
        for(int i=0,j=people.size()-1;i<=j;){
            if(people[i]+people[j]<=limit){
                i++;
                j--;
            }
            else i++;
            ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi people{3,2,2,1};
    int limit=3;
    auto ans=sol.numRescueBoats(people,limit);
    DBG(ans);

    system("pause");
    return 0;
}
