#include "utils.h"

class Solution {
public:
    //简单模拟即可，虽然时间复杂度很高但是常数很小
    int countTriples(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int a=i*i+j*j;
                for(int k=1;k<=n;k++){
                    if(a==k*k)ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.countTriples(n);
    DBG(ans);

    system("pause");
    return 0;
}
