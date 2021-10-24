#include "utils.h"

class Solution {
    bool check(int n){
        int cnt[10]={0};
        for(char c:to_string(n)){
            cnt[c-'0']++;
        }
        for(int i=0;i<10;i++){
            if(!cnt[i])continue;
            if(cnt[i]==i)continue;
            return false;
        }
        return true;
    }
public:
    //简单模拟，一直自加到合格为止
    int nextBeautifulNumber(int n) {
        while(!check(++n));
        return n;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=1000;
    auto ans=sol.nextBeautifulNumber(n);
    DBG(ans);

    system("pause");
    return 0;
}