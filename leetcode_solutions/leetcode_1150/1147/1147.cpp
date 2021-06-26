#include "utils.h"

class Solution {
public:
    int longestDecomposition(string text) {
        int n=text.size();
        int ans=0;
        for(int l=0,r=n-1,i;l<=r;l+=i,r-=i){
            for(i=1;l+i-1<r-i+1&&text.substr(l,i)!=text.substr(r-i+1,i);i++);
            if(l+i-1>=r-i+1)ans++;
            else ans+=2;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string text="ghiabcdefhelloadamhelloabcdefghi";
    auto ans=sol.longestDecomposition(text);
    DBG(ans);

    system("pause");
    return 0;
}
