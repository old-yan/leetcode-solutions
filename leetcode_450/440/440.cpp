#include "utils.h"

class Solution {
    string nn;
    string ans;
    int unit[10]={0,1,11,111,1111,11111,111111,1111111,11111111,111111111};
    void fun(int cur,int k){
        if(cur){
            if(k==1)return;
            k--;
        }
        string temp=nn.substr(0,cur);
        int startWith[10];
        if(ans==temp){
            int j=nn[cur]-'0';
            REP(i,j){
                startWith[i]=unit[nn.size()-cur];
            }
            FOR(i,j+1,10){
                startWith[i]=unit[nn.size()-cur-1];
            }
            startWith[j]=unit[nn.size()-cur-1]+s2i(nn.substr(cur+1,nn.size()-cur-1))+1;
        }
        else if(ans<temp){
            REP(i,10){
                startWith[i]=unit[nn.size()-cur];
            }
        }
        else if(ans>temp){
            REP(i,10){
                startWith[i]=unit[nn.size()-cur-1];
            }
        }
        if(!cur)startWith[0]=0;
        int cnt=0;
        REP(i,10){
            if(cnt+startWith[i]>=k){
                ans+='0'+i;
                fun(cur+1,k-cnt);
                return;
            }
            else cnt+=startWith[i];
        }
    }
public:
    int findKthNumber(int n, int k) {
        nn=i2s(n);
        fun(0,k);
        return s2i(ans);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4321;
    int k=4300;
    auto ans=sol.findKthNumber(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
