#include "utils.h"

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        auto next1=next_different(name);
        auto next2=next_different(typed);
        for(int i=0,j=0;i<next1.size();){
            if(name[i]!=typed[j])return false;
            if(next1[i]-i>next2[j]-j)return false;
            i=next1[i];
            j=next2[j];
            if(name[i]&&!typed[j])return false;
            if(!name[i]&&typed[j])return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string name="alex";
    string typed="aaleex";
    auto ans=sol.isLongPressedName(name,typed);
    DBG(ans);

    system("pause");
    return 0;
}
