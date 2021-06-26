#include "utils.h"

class Solution {
    struct{
        int cnt[26]={0},unique=0;
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
    int countGoodSubstrings(string s) {
        int n=s.size();
        if(n<3)return 0;
        int ans=0;
        for(int left=0,right=0;left<s.size()-2;left++){
            while(right<left+3)
                counter.add(s[right++]-'a');
            if(counter.unique==3)ans++;
            counter.remove(s[left]-'a');
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="xyzzaz";
    auto ans=sol.countGoodSubstrings(s);
    DBG(ans);

    system("pause");
    return 0;
}
