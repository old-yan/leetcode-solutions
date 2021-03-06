#include "utils.h"

class Solution {
public:
    bool canTransform(string start, string end) {
        int i=-1,j=-1;
        while(true){
            i=start.find_first_not_of('X',i+1);
            j=end.find_first_not_of('X',j+1);
            if(i<0&&j<0)break;
            if(i<0||j<0)return false;
            if(start[i]!=end[j])return false;
            if(start[i]=='L'){
                if(i<j)return false;
            }
            else{
                if(i>j)return false;
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string start="RXXLRXRXL";
    string end="XRLXXRRLX";
    auto ans=sol.canTransform(start,end);
    DBG(ans);

    system("pause");
    return 0;
}
