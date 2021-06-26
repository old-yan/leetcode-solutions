#include "SegTree.h"
#include "Heap.h"
#include "utils.h"

SegTree<int>T(1000,[](int x,int y){return max(x,y);});
class Solution {
    vi leftBigger,rightBigger;
    void getBorder(vi&arr){
        leftBigger.resize(arr.size(),-1);
        rightBigger.resize(arr.size(),arr.size());
        stack<int>S;
        REP(i,arr.size()){
            while(S.size()&&arr[S.top()]<arr[i]){
                rightBigger[S.top()]=i;
                S.pop();
            }
            if(S.size())leftBigger[i]=S.top();
            else leftBigger[i]=-1;
            while(S.size()&&arr[S.top()]==arr[i]){
                rightBigger[S.top()]=i;
                S.pop();
            }
            S.push(i);
        }
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        getBorder(arr);
        auto comp=[&](int x,int y){
            return arr[x]>arr[y];
        };
        BiHeap<int>H(comp);
        REP(i,arr.size())H.push(i);
        T.set(0);
        while(H.size()){
            auto p=H.top();
            H.pop();
            int l=max(p-d,leftBigger[p]+1);
            int r=min(p+d,rightBigger[p]-1);
            T.set(p,T(l,r)+1);
        }
        return T(0,arr.size()-1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{6,4,14,6,8,13,9,7,10,6,12};
    int d=2;
    auto ans=sol.maxJumps(arr,d);
    DBG(ans);

    system("pause");
    return 0;
}
