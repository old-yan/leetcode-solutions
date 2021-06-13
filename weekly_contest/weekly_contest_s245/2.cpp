#include "utils.h"

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low=0,high=removable.size();
        int del_pos[s.size()];
        memset(del_pos,0x3f,sizeof(del_pos));
        REP(i,removable.size())del_pos[removable[i]]=i;
        while(low<high){
            int mid=(low+high+1)/2;
            int cursor=0;
            REP(i,s.size()){
                if(del_pos[i]>=mid&&s[i]==p[cursor])cursor++;
            }
            if(cursor==p.size())low=mid;
            else high=mid-1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abcacb";
    string p="ab";
    vi removable{3,1,0};
    auto ans=sol.maximumRemovals(s,p,removable);
    DBG(ans);

    system("pause");
    return 0;
}
