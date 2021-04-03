#include "utils.h"

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int>Q;
        REP(i,deck.size())Q.push(i);
        sort(ALL(deck));
        auto cur=deck.begin();
        vi ans;
        while(Q.size()){
            ans[Q.front()]=*cur++;
            Q.pop();
            if(Q.size()){
                Q.push(Q.front());
                Q.pop();
            }
            else break;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi deck{17,13,11,2,3,5,7};
    auto ans=sol.deckRevealedIncreasing(deck);
    DBGV(ans);

    system("pause");
    return 0;
}
