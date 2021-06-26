#include "utils.h"

class Solution {
public:
    string getHint(string secret, string guess) {
        int num1[128]={0};
        int num2[128]={0};
        int bulls=0,cows=0;
        REP(i,secret.size()){
            if(secret[i]==guess[i])bulls++;
            else{
                num1[secret[i]]++;
                num2[guess[i]]++;
            }
        }
        REP(i,128){
            cows+=min(num1[i],num2[i]);
        }
        return i2s(bulls)+"A"+i2s(cows)+"B";
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string secret="1123";
    string guess="0111";
    auto ans=sol.getHint(secret,guess);
    DBG(ans);

    system("pause");
    return 0;
}
