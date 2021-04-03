#include "utils.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>S;
        for(auto&e:emails){
            int i=e.find('@');
            string s;
            REP(j,i){
                if(e[j]=='+')break;
                if(e[j]=='.')continue;
                s+=e[j];
            }
            S.insert(s+e.substr(i));
        }
        return S.size();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>emails{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    auto ans=sol.numUniqueEmails(emails);
    DBG(ans);

    system("pause");
    return 0;
}
