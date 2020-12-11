#include "utils.h"

class Solution {
public:
    int romanToInt(string s) {
        int val=0;
        map<char,int>M1{
            {'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}
        };
        map<string,int>M2{
            {"CD",400},{"CM",900},{"XL",40},{"XC",90},{"IV",4},{"IX",9}
        };
        REP(i,s.size()){
            if(M2.count(s.substr(i,2))){
                val+=M2[s.substr(i++,2)];
            }
            else{
                val+=M1[s[i]];
            }
        }
        return val;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="MCMXCIV";
    auto ans=sol.romanToInt(s);
    DBG(ans);

    system("pause");
    return 0;
}
