#include "utils.h"

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>sta;
        for(char c:s){
            if(sta.size()&&sta.back().first==c){
                if(++sta.back().second==k)sta.pop_back();
            }
            else sta.emplace_back(c,1);
        }
        string ans;
        for(auto [c,i]:sta){
            while(i--)ans+=c;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="deeedbbcccbdaa";
    int k=3;
    auto ans=sol.removeDuplicates(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
