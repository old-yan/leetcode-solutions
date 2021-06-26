#include "utils.h"

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>M;
        for(int a:answers)M[a+1]++;
        int ans=0;
        for(auto&it:M){
            ans+=((it.second-1)/it.first+1)*it.first;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi answers{1,1,2};
    auto ans=sol.numRabbits(answers);
    DBG(ans);

    system("pause");
    return 0;
}
