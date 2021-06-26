#include "utils.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>S;
        int i=0,j=0;
        while(j<popped.size()){
            if(S.size()&&S.top()==popped[j]){
                S.pop();
                j++;
            }
            else if(i<pushed.size()){
                S.push(pushed[i++]);
            }
            else break;
        }
        return i==j;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi pushed{1,2,3,4,5};
    vi popped{4,3,5,1,2};
    auto ans=sol.validateStackSequences(pushed,popped);
    DBG(ans);

    system("pause");
    return 0;
}
