#include "utils.h"

class Solution {
    string enums[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    string tens[10]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string teens[10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string>insideThousand(int num){
        vector<string>res;
        if(num/100){
            res.pb(enums[num/100]);
            res.pb("Hundred");
            num%=100;
        }
        if(num/10>=2){
            res.pb(tens[num/10]);
            if(num%10)res.pb(enums[num%10]);
        }
        else if(num/10==1){
            res.pb(teens[num%10]);
        }
        else if(num)res.pb(enums[num]);
        return res;
    }
public:
    string numberToWords(int num) {
        if(!num)return enums[0];
        vector<string>collect;
        if(num/1000000000){
            auto res=insideThousand(num/1000000000);
            collect.insert(collect.end(),ALL(res));
            collect.pb("Billion");
        }
        if(num%1000000000/1000000){
            auto res=insideThousand(num%1000000000/1000000);
            collect.insert(collect.end(),ALL(res));
            collect.pb("Million");
        }
        if(num%1000000/1000){
            auto res=insideThousand(num%1000000/1000);
            collect.insert(collect.end(),ALL(res));
            collect.pb("Thousand");
        }
        if(num%1000){
            auto res=insideThousand(num%1000);
            collect.insert(collect.end(),ALL(res));
        }
        string ans;
        for(string&s:collect){
            if(ans.size())ans+=" ";
            ans+=s;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=1234567891;
    auto ans=sol.numberToWords(num);
    DBG(ans);

    system("pause");
    return 0;
}
