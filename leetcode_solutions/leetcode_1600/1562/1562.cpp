#include "utils.h"

int Left[100002],Right[100002],cnt[100002];
class Solution {
    int findLeft(int i){
        if(Left[i]==i)return i;
        else return Left[i]=findLeft(Left[i]);
    }
    int findRight(int i){
        if(Right[i]==i)return i;
        else return Right[i]=findRight(Right[i]);
    };
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size(),ans=-1;
        fill(Left,Left+n+2,n+1);
        fill(Right,Right+n+2,0);
        fill(cnt,cnt+n+1,0);
        REP(i,n){
            int l=arr[i],r=arr[i];
            if(arr[i]>1&&chmin(l,findLeft(arr[i]-1))){
                cnt[arr[i]-l]--;
            }
            if(arr[i]<n&&chmax(r,findRight(arr[i]+1))){
                cnt[r-arr[i]]--;
            }
            Left[arr[i]]=l;
            if(arr[i]<n&&Right[arr[i]+1])Left[arr[i]+1]=l;
            Right[arr[i]]=r;
            if(arr[i]>1&&Right[arr[i]-1])Right[arr[i]-1]=r;
            cnt[r-l+1]++;
            if(cnt[m])ans=i+1;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{3,5,1,2,4};
    int m=1;
    auto ans=sol.findLatestStep(arr,m);
    DBG(ans);

    system("pause");
    return 0;
}
