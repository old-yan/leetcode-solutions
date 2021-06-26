#include "utils.h"

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans(k);
        sort(ALL(words));
        vi next=next_different(words);
        auto comp=[&](int x,int y){
            return next[x]-x>next[y]-y||(next[x]-x==next[y]-y&&x<y);
        };
        priority_queue<int,vi,decltype(comp)>Q(comp);
        for(int i=0;i<next.size();i=next[i]){
            Q.push(i);
            if(Q.size()>k)Q.pop();
        }
        for(int i=k-1;i>=0;i--){
            ans[i]=words[Q.top()];
            Q.pop();
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{"i", "love", "leetcode", "i", "love", "coding"};
    int k=2;
    auto ans=sol.topKFrequent(words,k);
    DBGV(ans);

    system("pause");
    return 0;
}
