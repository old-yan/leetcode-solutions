#include "utils.h"

class Solution {
public:
    int numSteps(string s) {
        deque<int>Q;
        for(char c:s)Q.pb(c-'0');
        int ans=0;
        while(Q.size()>1){
            if(Q.back()==1){
                int jinwei=1;
                REPR(i,Q.size()-1){
                    Q[i]+=jinwei;
                    jinwei=Q[i]/2;
                    Q[i]%=2;
                }
                if(jinwei)Q.push_front(1);
            }
            else{
                Q.pop_back();
            }
            ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="1101";
    auto ans=sol.numSteps(s);
    DBG(ans);

    system("pause");
    return 0;
}
