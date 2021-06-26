#include "utils.h"

class Solution {
public:
    bool checkPartitioning(string s) {
        //先生成马拉车数组
        vi arm=getarm(s);
        //后续利用马拉车判断对称情况
        for(int i=0;i<s.size()-2;i++){
            if(!query_polindromic(arm,0,i))continue;
            for(int j=i+1;j<s.size()-1;j++){
                if(!query_polindromic(arm,i+1,j))continue;
                if(query_polindromic(arm,j+1,s.size()-1))return true;
            }
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="bcbddxy";
    auto ans=sol.checkPartitioning(s);

    system("pause");
    return 0;
}
