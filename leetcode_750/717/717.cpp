#include "utils.h"

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(int i=0;i<bits.size();){
            if(bits[i]){
                i+=2;
                if(i==bits.size())return false;
            }
            else{
                i++;
                if(i==bits.size())return true;
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi bits{1,1,1,0};
    auto ans=sol.isOneBitCharacter(bits);
    DBG(ans);

    system("pause");
    return 0;
}
