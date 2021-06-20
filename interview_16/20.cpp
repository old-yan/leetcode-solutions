#include "utils.h"

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        bool can[128][128]={0};
        string s[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        FOR(i,2,10){
            for(char c:s[i]){
                can['0'+i][c]=true;
            }
        }
        vector<string>ans;
        for(string&w:words)if(w.size()==num.size()){
            bool b=true;
            REP(i,num.size()){
                if(!can[num[i]][w[i]]){
                    b=false;
                    break;
                }
            }
            if(b)ans.pb(w);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num="8733";
    vector<string>words{
        "tree","used"
    };
    auto ans=sol.getValidT9Words(num,words);
    DBGV(ans);

    system("pause");
    return 0;
}
