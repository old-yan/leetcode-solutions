#include "utils.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        priority_queue<int,deque<int>,greater<int>>Q;
        for(int a:citations)Q.push(a);
        int ans=0;;
        REP(i,citations.size()+1){
            while(Q.size()&&Q.top()<i)Q.pop();
            if(Q.size()==i)chmax(ans,int(i));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi citaions{2,0,6,1,5};
    auto ans=sol.hIndex(citaions);
    DBG(ans);

    system("pause");
    return 0;
}
