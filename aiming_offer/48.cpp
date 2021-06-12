#include "utils.h"

class Solution {
    struct{
        int cnt[128]={0},unique=0;
        void add(int c){
            if(cnt[c]==1)unique--;
            cnt[c]++;
            if(cnt[c]==1)unique++;
        }
        void remove(int c){
            if(cnt[c]==1)unique--;
            cnt[c]--;
            if(cnt[c]==1)unique++;
        }
    }counter;
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        for(int left=0,right=0;right<=s.size();right++){
            while(left<right&&counter.unique!=right-left){
                counter.remove(s[left++]);
            }
            chmax(ans,right-left);
            if(s[right])counter.add(s[right]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abcabcbb";
    auto ans=sol.lengthOfLongestSubstring(s);
    DBG(ans);

    system("pause");
    return 0;
}
