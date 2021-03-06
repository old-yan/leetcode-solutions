#include "utils.h"

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int num[26]={0};
        for(char c:S)num[c-'a']++;
        vi ans;
        for(int i=0,j;i<S.size();i=j+1){
            int rest=0;
            bool have[26]={0};
            for(j=i;j<S.size();j++){
                if(!have[S[j]-'a']){
                    have[S[j]-'a']=true;
                    rest+=num[S[j]-'a'];
                }
                if(!--rest)break;
            }
            ans.pb(j-i+1);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="ababcbacadefegdehijhklij";
    auto ans=sol.partitionLabels(S);
    DBGV(ans);

    system("pause");
    return 0;
}
