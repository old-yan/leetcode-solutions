#include "utils.h"

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int cur=0,cnt[26]={0};
        REP(i,releaseTimes.size()){
            chmax(cnt[keysPressed[i]-'a'],releaseTimes[i]-cur);
            cur=releaseTimes[i];
        }
        int Max=*max_element(cnt,cnt+26);
        REPR(c,25)if(cnt[c]==Max)return 'a'+c;
        return ' ';
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi releaseTimes{9,29,49,50};
    string keysPressed="cbcd";
    auto ans=sol.slowestKey(releaseTimes,keysPressed);
    DBG(ans);

    system("pause");
    return 0;
}
