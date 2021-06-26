#include "utils.h"

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string,int>M;
        for(int i=0,j;i<A.size();i=j+1){
            j=A.find_first_of(' ',i);
            if(j<0)j=A.size();
            M[A.substr(i,j-i)]++;
        }
        for(int i=0,j;i<B.size();i=j+1){
            j=B.find_first_of(' ',i);
            if(j<0)j=B.size();
            M[B.substr(i,j-i)]++;
        }
        vector<string>ans;
        for(auto&it:M){
            if(it.second==1)ans.pb(it.first);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string A="this apple is sweet";
    string B="this apple is sour";
    auto ans=sol.uncommonFromSentences(A,B);
    DBGV(ans);

    system("pause");
    return 0;
}
