#include "utils.h"

class Solution {
    bool dfs(string&S,int cur,vi&path){
        if(cur==S.size())return true;
        ll next=(ll)path[path.size()-2]+(ll)path[path.size()-1];
        if(next>INT_MAX)return false;
        string s=i2s(next);
        if(cur+s.size()>S.size())return false;
        if(S.substr(cur,s.size())==s){
            path.pb(next);
            if(dfs(S,cur+s.size(),path))return true;
            path.pop_back();
        }
        return false;
    }
public:
    vector<int> splitIntoFibonacci(string S) {
        for(int first=1;first<=10;first++){
            if(first>=S.size())break;
            if(first>1&&S[0]=='0')break;
            ll first_num=s2i(S.substr(0,first));
            if(first_num>INT_MAX)break;
            for(int second=1;second<=10;second++){
                if(first+second>=S.size())break;
                if(second>1&&S[first]=='0')break;
                ll second_num=s2i(S.substr(first,second));
                if(second_num>INT_MAX)break;
                vi path{int(first_num),int(second_num)};
                if(dfs(S,first+second,path))return path;
            }
        }
        return {};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="123456789";
    auto ans=sol.splitIntoFibonacci(S);
    DBGV(ans);

    system("pause");
    return 0;
}
