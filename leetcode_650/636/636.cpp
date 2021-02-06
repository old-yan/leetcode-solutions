#include "utils.h"

class Solution {
    vi ans;
    vector<string>logs;
    int fun(int&idx){
        int i=logs[idx].find_first_of(':',0);
        int j=logs[idx].find_first_of(':',i+1);
        string function=logs[idx].substr(0,i);
        int function_idx=s2i(function);
        int starttime=s2i(logs[idx].substr(i+7,logs[idx].size()-i-7));
        int pausetime=0;
        ++idx;
        while(true){
            if(logs[idx].substr(0,i)==function&&logs[idx][i+1]=='e')break;
            pausetime+=fun(idx);
        }
        int stoptime=s2i(logs[idx].substr(i+5,logs[idx].size()-i-5));
        ans[function_idx]+=stoptime-starttime+1-pausetime;
        idx++;
        return stoptime-starttime+1;
    }
public:
    vector<int> exclusiveTime(int n, vector<string>&_logs) {
        ans.resize(n,0);
        logs=_logs;
        int idx=0;
        while(idx<logs.size()){
            fun(idx);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    vector<string>logs{
        "0:start:0","1:start:2","1:end:5","0:end:6"
    };
    auto ans=sol.exclusiveTime(n,logs);
    DBGV(ans);

    system("pause");
    return 0;
}
