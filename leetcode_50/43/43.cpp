#include "utils.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";
        int s1[200]={0},s2[200]={0},s3[400]={0};
        REPR(i,num1.size()-1)s1[num1.size()-1-i]=num1[i]-'0';
        REPR(i,num2.size()-1)s2[num2.size()-1-i]=num2[i]-'0';
        REP(i,num1.size()){
            REP(j,num2.size()){
                s3[i+j]+=s1[i]*s2[j];
            }
        }
        ll maxdigit=0;
        REP(i,300){
            s3[i+1]+=s3[i]/10;
            s3[i]%=10;
            if(s3[i])chmax(maxdigit,i);
        }
        DBG(maxdigit);
        string ans;
        FORR(i,maxdigit,0)ans+=char('0'+s3[i]);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num1="123";
    string num2="456";
    auto ans=sol.multiply(num1,num2);
    DBG(ans);

    system("pause");
    return 0;
}
