#include "utils.h"

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        //all表示从1到n的所有数的异或值
        int all=0;
        for(int i=1;i<=encoded.size()+1;i++)all^=i;
        //except_first表示原数组中除第一项外的异或值
        int except_first=0;
        //enc[1]包含了原数组1~2,enc[3]包含了原数组3~4,enc[5]包含了原数组5~6...
        for(int i=1;i<encoded.size();i+=2)except_first^=encoded[i];
        vi ans;
        //all和except_first异或，消去后面的，求出第一项
        ans.pb(all^except_first);
        for(int a:encoded){
            ans.pb(ans.back()^a);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi encoded{6,5,4,6};
    auto ans=sol.decode(encoded);
    DBGV(ans);

    system("pause");
    return 0;
}