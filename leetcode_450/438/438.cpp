#include "utils.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())return {};
        int num[128]={0};
        int non_zero=0;
        for(char c:p){
            if(!num[c]++)non_zero++;
        }
        vi ans;
        for(int i=0,j=0;i<=s.size()-p.size();i++){
            while(j<i+p.size()){
                char c=s[j++];
                --num[c];
                if(num[c]==0)non_zero--;
                else if(num[c]==-1)non_zero++;
            }
            if(non_zero==0)ans.pb(i);
            char c=s[i];
            ++num[c];
            if(num[c]==0)non_zero--;
            else if(num[c]==1)non_zero++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="cbaebabacd";
    string p="abc";
    auto ans=sol.findAnagrams(s,p);
    DBGV(ans);

    system("pause");
    return 0;
}
