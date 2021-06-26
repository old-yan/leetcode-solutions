#include "utils.h"

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>Q(ALL(stones));
        while(Q.size()>1){
            auto p=Q.top();
            Q.pop();
            auto q=Q.top();
            Q.pop();
            if(p!=q)Q.push(abs(p-q));
        }
        return Q.size()?Q.top():0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi stones{2,7,4,1,8,1};
    auto ans=sol.lastStoneWeight(stones);
    DBG(ans);

    system("pause");
    return 0;
}
