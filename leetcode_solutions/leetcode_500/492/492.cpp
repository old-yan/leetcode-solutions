#include "utils.h"

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L,W;
        REPR(i,sqrt(area)){
            if(area%i==0){
                L=area/i;
                W=i;
                break;
            }
        }
        return {L,W};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int area=12;
    auto ans=sol.constructRectangle(area);
    DBGV(ans);

    system("pause");
    return 0;
}
