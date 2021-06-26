#include "utils.h"

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string>v;
        for(int i=0,j;i<preorder.size();i=j+1){
            for(j=i+1;preorder[j]&&preorder[j]!=',';j++);
            v.push_back(preorder.substr(i,j-i));
        }
        int count=1;
        REP(i,v.size()){
            if(v[i]=="#"){
                if(--count==0){
                    return i==v.size()-1;
                }
            }
            else count++;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string preoeder="9,3,4,#,#,1,#,#,2,#,6,#,#";
    auto ans=sol.isValidSerialization(preoeder);
    DBG(ans);

    system("pause");
    return 0;
}
