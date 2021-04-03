#include <cstring>
#include "utils.h"

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vi alpha,digit;
        string help[logs.size()];
        REP(i,logs.size()){
            if(isalpha(logs[i].back())){
                alpha.pb(i);
                int j=logs[i].find(' ');
                FOR(k,j,logs[i].size()){
                    if(logs[i][k]!=' ')help[i]+=logs[i][k];
                }
            }
            else{
                digit.pb(i);
            }
        }
        sort(ALL(alpha),[&](int x,int y){
            int res=strcmp(&help[x][0],&help[y][0]);
            if(res)return res<0;
            return strcmp(&logs[x][0],&logs[y][0])<0;
        });
        vector<string>ans;
        for(int idx:alpha){
            ans.pb(logs[idx]);
        }
        for(int idx:digit){
            ans.pb(logs[idx]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>logs{"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    auto ans=sol.reorderLogFiles(logs);
    DBGV(ans);

    system("pause");
    return 0;
}
