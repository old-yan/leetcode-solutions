#include "utils.h"

class Solution {
    string fun(string S,ll idx,ll cur,ll K){
        ll i,j;
        for(i=idx;isalpha(S[i]);i++);
        if(K<=cur+i-idx)return S.substr(idx+K-cur-1,1);
        ll len=(cur+i-idx)*(S[i]-'0');
        if(len>=K){
            ll rest=(K-1)%(cur+i-idx);
            if(rest<cur)return fun(S.substr(0,idx),0,0,rest+1);
            else return S.substr(idx+(K-1)%(i-idx),1);
        }
        else return fun(S,i+1,len,K);
    }
public:
    string decodeAtIndex(string S, int K) {
        return fun(S,0,0,K);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="vzpp636m8y";
    int K=2920;
    auto ans=sol.decodeAtIndex(S,K);
    DBG(ans);

    system("pause");
    return 0;
}
