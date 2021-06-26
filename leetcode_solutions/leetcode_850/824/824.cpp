#include "utils.h"

class Solution {
public:
    string toGoatLatin(string S) {
        int type[128]={0};
        type['a']=type['e']=type['i']=type['o']=type['u']=1;
        type['A']=type['E']=type['I']=type['O']=type['U']=1;
        string ans;
        for(int i=0,j,k=1;i<S.size();i=j+1,k++){
            if(ans.size())ans+=' ';
            j=S.find_first_of(' ',i);
            if(j<0)j=S.size();
            if(type[S[i]]==1){
                ans+=S.substr(i,j-i)+"ma";
            }
            else{
                ans+=S.substr(i+1,j-i-1)+S[i]+"ma";
            }
            REP(_,k)ans+='a';
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="I speak Goat Latin";
    auto ans=sol.toGoatLatin(S);
    DBG(ans);

    system("pause");
    return 0;
}
