#include "utils.h"

class Solution {
public:
    string printBin(double num) {
        bitset<64>b(*(long*)&num);
        string s="1"+b.to_string().substr(12);
        int unit=0;
        for(int i=62;i>51;i--)
            unit=unit*2+b[i];
        unit-=1024;
        s="0."+string(-2-unit,'0')+s;
        while(s.back()=='0')s.pop_back();
        if(s.size()<=32)return s;
        else return "ERROR";
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    double num=0.625;
    auto ans=sol.printBin(num);
    DBG(ans);

    system("pause");
    return 0;
}
