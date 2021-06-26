#include "utils.h"

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num5=0,num10=0;
        for(int b:bills){
            if(b==5)num5++;
            else if(b==10){
                if(!num5--)return false;
                num10++;
            }
            else{
                if(num10){
                    num10--;
                    if(!num5--)return false;
                }
                else{
                    if(num5<3)return false;
                    num5-=3;
                }
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi bills{5,5,5,10,20};
    auto ans=sol.lemonadeChange(bills);
    DBG(ans);

    system("pause");
    return 0;
}
