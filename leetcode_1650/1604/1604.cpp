#include "utils.h"

class Solution {
    unordered_map<string,vi>M;
    int toint(string&t){
        return ((t[0]-'0')*10+t[1]-'0')*60+(t[3]-'0')*10+t[4]-'0';
    }
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        REP(i,keyName.size()){
            M[keyName[i]].pb(toint(keyTime[i]));
        }
        vector<string>ans;
        for(auto&it:M){
            auto&v=it.second;
            sort(ALL(v));
            for(int i=0,j=0;i<v.size();i++){
                while(j<v.size()&&v[j]<=v[i]+60)j++;
                if(j>=i+3){
                    ans.pb(it.first);
                    break;
                }
            }
        }
        sort(ALL(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>keyName{"daniel","daniel","daniel","luis","luis","luis","luis"};
    vector<string>keyTime{"10:00","10:40","11:00","09:00","11:00","13:00","15:00"};
    auto ans=sol.alertNames(keyName,keyTime);
    DBGV(ans);

    system("pause");
    return 0;
}
