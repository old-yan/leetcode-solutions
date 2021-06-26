#include "utils.h"

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxlen=0;
        for(auto&rec:rectangles){
            chmax(maxlen,min(rec[0],rec[1]));
        }
        int ans=0;
        for(auto&rec:rectangles){
            ans+=maxlen==min(rec[0],rec[1]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi rectangles=makevvi("[[5,8],[3,9],[5,12],[16,5]]");
    auto ans=sol.countGoodRectangles(rectangles);
    DBG(ans);

    system("pause");
    return 0;
}
