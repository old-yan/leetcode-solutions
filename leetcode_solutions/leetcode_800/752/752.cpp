#include "utils.h"

class Solution {
    const int units[4]={1,10,100,1000};
public:
    int openLock(vector<string>& deadends, string target) {
        int ans=0;
        int target_num=s2i(target);
        if(!target_num)return ans;
        int state[10000]={0};
        for(string&end:deadends)state[s2i(end)]=-1;
        if(state[0]<0)return -1;
        queue<int>Q;
        state[0]=1;
        Q.emplace(0);
        while(int l=Q.size()){
            ans++;
            while(l--){
                auto p=Q.front();
                Q.pop();
                for(int unit:units){
                    int digit=p/unit%10;
                    int lower=digit?p-unit:p+9*unit;
                    if(!state[lower]){
                        state[lower]=1;
                        Q.push(lower);
                    }
                    int upper=digit<9?p+unit:p-9*unit;
                    if(!state[upper]){
                        state[upper]=1;
                        Q.push(upper);
                    }
                }
                if(state[target_num])return ans;
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>deadends{"0201","0101","0102","1212","2002"};
    string target="0202";
    auto ans=sol.openLock(deadends,target);
    DBG(ans);

    system("pause");
    return 0;
}
