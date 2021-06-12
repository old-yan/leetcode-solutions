#include "utils.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int cursor=0;
        stack<int>S;
        for(int a:pushed){
            S.push(a);
            while(S.size()&&S.top()==popped[cursor]){
                S.pop();
                cursor++;
            }
        }
        return S.empty();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi pushed{1,2,3,4,5};
    vi popped{4,5,3,2,1};
    auto ans=sol.validateStackSequences(pushed,popped);
    DBG(ans);

    system("pause");
    return 0;
}
