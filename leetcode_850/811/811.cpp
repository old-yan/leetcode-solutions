#include "utils.h"

class Solution {
    vector<string>ans;
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>M;
        for(auto&domain:cpdomains){
            int val=0;
            int i;
            for(i=0;isdigit(domain[i]);i++)val=val*10+domain[i]-'0';
            while(i+1){
                M[domain.substr(i+1)]+=val;
                i=domain.find_first_of('.',i+1);
            }
        }
        for(auto&it:M){
            ans.pb(i2s(it.second)+' '+it.first);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>cpdomains{"9001 discuss.leetcode.com"};
    auto ans=sol.subdomainVisits(cpdomains);
    DBGV(ans);

    system("pause");
    return 0;
}
