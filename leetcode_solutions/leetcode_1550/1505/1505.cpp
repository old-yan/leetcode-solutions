#include "SegTree.h"
#include "utils.h"

SegTree<int>T(30000,[](int x,int y){return x+y;});
class Solution {
    queue<int>pos[10];
public:
    string minInteger(string num, int k) {
        T.set(1);
        REP(i,num.size())pos[num[i]-'0'].push(i);
        string ans;
        for(int i=0;i<num.size();i++){
            if(!T[i])continue;
            REP(c,num[i]-'0'){
                while(pos[c].size()){
                    int a=T(i+1,pos[c].front());
                    if(a>k)break;
                    k-=a;
                    ans+=num[pos[c].front()];
                    T.set(pos[c].front(),0);
                    pos[c].pop();
                }
            }
            ans+=num[i];
            pos[num[i]-'0'].pop();
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num="345";
    int k=4;
    auto ans=sol.minInteger(num,k);
    DBG(ans);

    system("pause");
    return 0;
}
