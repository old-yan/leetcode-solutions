#include "utils.h"

class Solution {
public:
    string fractionAddition(string expression) {
        Fraction frac(0);
        for(int i=0,j;i<expression.size();i=j){
            for(j=i+1;expression[j]&&expression[j]!='+'&&expression[j]!='-';j++);
            frac+=Fraction(expression.substr(i,j-i));
        }
        return i2s(frac.signal*frac.numerator)+"/"+i2s(frac.denominator);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string expression="-1/2+1/2+1/3";
    auto ans=sol.fractionAddition(expression);
    DBG(ans);

    system("pause");
    return 0;
}
