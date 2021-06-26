#include "utils.h"

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i,j;
        vi v1,v2;
        for(i=0;i<version1.size();i=j+1){
            for(j=i+1;j<version1.size()&&isdigit(version1[j]);j++);
            v1.pb(s2i(version1.substr(i,j-i)));
        }
        for(i=0;i<version2.size();i=j+1){
            for(j=i+1;j<version2.size()&&isdigit(version2[j]);j++);
            v2.pb(s2i(version2.substr(i,j-i)));
        }
        while(v1.size()<v2.size())v1.pb(0);
        while(v2.size()<v1.size())v2.pb(0);
        if(v1<v2)return -1;
        else if(v1==v2)return 0;
        else return 1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string version1="1.01";
    string version2="1.001";
    auto ans=sol.compareVersion(version1,version2);
    DBG(ans);

    system("pause");
    return 0;
}
