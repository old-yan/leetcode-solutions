#include "utils.h"

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(first.size()==second.size()){
            int dif=0;
            REP(i,first.size())dif+=first[i]!=second[i];
            return dif<=1;
        }
        else if(abs(int(first.size())-int(second.size()))!=1)return false;
        else{
            if(first.size()>second.size())swap(first,second);
            int cursor=0;
            while(first[cursor]==second[cursor])cursor++;
            while(first[cursor]&&first[cursor]==second[cursor+1])cursor++;
            return !first[cursor];
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string first="pale";
    string second="ple";
    auto ans=sol.oneEditAway(first,second);
    DBG(ans);

    system("pause");
    return 0;
}
