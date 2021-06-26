#include "utils.h"

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(ALL(staple));
        sort(ALL(drinks));
        ll ans=0;
        for(int i=0,j=drinks.size()-1;i<staple.size();i++){
            while(j>=0&&staple[i]+drinks[j]>x)j--;
            if(j<0)break;
            ans+=j+1;
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi staple{10,20,5};
    vi drinks{5,5,2};
    int x=15;
    auto ans=sol.breakfastNumber(staple,drinks,x);
    DBG(ans);

    system("pause");
    return 0;
}
