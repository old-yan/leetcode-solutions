#include "utils.h"

const string numbers[]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
const string tens[]={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
const string teens[]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
class Solution {
    string func(int num){
        string res;
        if(num>=100){
            if(res.size())res+=" ";
            res+=numbers[num/100];
            res+=" Hundred";
            num%=100;
        }
        if(num>=20){
            if(res.size())res+=" ";
            res+=tens[num/10];
            num%=10;
        }
        else if(num>=10){
            if(res.size())res+=" ";
            res+=teens[num-10];
            num=0;
        }
        if(num){
            if(res.size())res+=" ";
            res+=numbers[num];
        }
        return res;
    }
public:
    string numberToWords(int num) {
        string ans;
        if(num>=1000000000){
            ans+=func(num/1000000000);
            ans+=" Billion";
            num%=1000000000;
        }
        if(num>=1000000){
            if(ans.size())ans+=' ';
            ans+=func(num/1000000);
            ans+=" Million";
            num%=1000000;
        }
        if(num>=1000){
            if(ans.size())ans+=' ';
            ans+=func(num/1000);
            ans+=" Thousand";
            num%=1000;
        }
        if(num){
            if(ans.size())ans+=' ';
            ans+=func(num);
        }
        if(ans.empty())return "Zero";
        else return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=123;
    auto ans=sol.numberToWords(num);
    DBG(ans);

    system("pause");
    return 0;
}
