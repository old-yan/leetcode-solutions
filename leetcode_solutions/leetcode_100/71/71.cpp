#include "utils.h"

class Solution {
public:
    string simplifyPath(string path) {
        vector<string>parents;
        REP(i,path.size()){
            while(path[i]&&path[i]=='/')i++;
            if(!path[i])break;
            string temp;
            while(path[i]&&path[i]!='/')temp+=path[i++];
            if(temp==".")continue;
            else if(temp==".."){
                if(parents.size())parents.pop_back();
            }
            else parents.pb('/'+temp);
        }
        string ans;
        for(string&s:parents)ans+=s;
        if(ans=="")ans+='/';
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string path="/home/";
    auto ans=sol.simplifyPath(path);
    DBG(ans);

    system("pause");
    return 0;
}
