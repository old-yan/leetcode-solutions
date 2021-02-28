#include "utils.h"

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vi ans;
        for(int a:asteroids){
            if(a>0){
                ans.pb(a);
            }
            else{
                while(ans.size()&&ans.back()>0&&ans.back()<-a)ans.pop_back();
                if(ans.empty()||ans.back()<0)ans.pb(a);
                else if(ans.back()==-a)ans.pop_back();
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi asteroids{5,10,-5};
    auto ans=sol.asteroidCollision(asteroids);
    DBGV(ans);

    system("pause");
    return 0;
}
