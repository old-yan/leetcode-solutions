#include "utils.h"

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n=clips.size();
        sort(ALL(clips));
        int cur=0,i=0,j=0,ans=0;
        multiset<int,greater<int>>S;
        while(cur<T){
            while(i<n&&clips[i][0]<=cur){
                S.insert(clips[i++][1]);
            }
            if(S.empty()||*S.begin()==cur)break;
            cur=*S.begin();
            while(j<i)S.erase(S.find(clips[j++][1]));
            ans++;
        }
        return cur<T?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi clips=makevvi("[[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]]");
    int T=10;
    auto ans=sol.videoStitching(clips,T);
    DBG(ans);

    system("pause");
    return 0;
}
