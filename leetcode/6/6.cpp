#include "utils.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<string>row(numRows,"");
        int y=0,dy;
        REP(i,s.size()){
            row[y]+=s[i];
            if(!y)dy=1;
            if(y==numRows-1)dy=-1;
            y+=dy;
        }
        string ans;
        for(string r:row)ans+=r;
        return ans;
    }
};

int main()
{
    Solution sol;

    string s="PAYPALISHIRING";
    auto ans=sol.convert(s,3);
    DBG(ans);

    system("pause");
    return 0;
}
