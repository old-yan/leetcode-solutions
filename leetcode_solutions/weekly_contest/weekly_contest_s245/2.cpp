#include "utils.h"

class Solution {
public:
    //利用二段性对移除数量进行二分
    //  移除得少，那么s的剩余字符能凑齐p
    //  移除得多，那么s的剩余字符不能凑齐p
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low=0,high=removable.size();
        //del_pos记录s的每个下标对应removable的移除时间
        //一会二分的时候，可以通过del_pos来判断s的某个下标是否移除
        int del_pos[s.size()];
        memset(del_pos,0x3f,sizeof(del_pos));
        REP(i,removable.size())del_pos[removable[i]]=i;
        while(low<high){
            int mid=(low+high+1)/2;
            int cursor=0;
            REP(i,s.size()){
                //如果s[i]未移除，且可以匹配p[cursor]，就将cursor前进一位
                if(del_pos[i]>=mid&&s[i]==p[cursor])cursor++;
            }
            //如果cursor来到p的末尾，说明s能凑齐p，mid值偏小，还可以往大走
            if(cursor==p.size())low=mid;
            //如果s没能凑齐p，mid值偏大，只能往小走
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
