#include "utils.h"

class Solution {
public:
    int minDays(int n) {
        unordered_set<int>S;
        queue<int>Q;
        S.insert(n);
        Q.push(n);
        int ans=0;
        while(int l=Q.size()){
            if(S.count(0))return ans;
            ans++;
            while(l--){
                auto p=Q.front();
                Q.pop();
                if(p%3==0&&S.insert(p/3).second){
                    Q.push(p/3);
                }
                if(p%2==0&&S.insert(p/2).second){
                    Q.push(p/2);
                }
                if(S.insert(p-1).second){
                    Q.push(p-1);
                }
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.minDays(n);
    DBG(ans);

    system("pause");
    return 0;
}
