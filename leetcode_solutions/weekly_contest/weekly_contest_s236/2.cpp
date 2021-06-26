#include "utils.h"

class Solution {
public:
    //暴力模拟即可
    int findTheWinner(int n, int k) {
        vector<int>v(n);
        iota(v.begin(),v.end(),1);
        int cur=0;
        while(v.size()>1){
            for(int i=k;--i;){
                cur=(cur+1)%v.size();
            }
            v.erase(v.begin()+cur);
            cur%=v.size();
        }
        return v[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    int k=2;
    auto ans=sol.findTheWinner(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
