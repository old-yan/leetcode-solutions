#include "Heap.h"
#include "utils.h"

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        double delta[n];
        auto getdelta=[&](int i){
            return double(classes[i][1]-classes[i][0])/(double(classes[i][1])*(classes[i][1]+1));
        };
        REP(i,n){
            delta[i]=getdelta(i);
        }
        auto comp=[&](int x,int y){return delta[x]<delta[y];};
        Heap<int>H(comp);
        REP(i,n)H.push(i);
        while(extraStudents--){
            auto p=H.top();
            classes[p][0]++;
            classes[p][1]++;
            delta[p]=getdelta(p);
            H.sink(p);
        }
        double ans=0;
        for(auto&Class:classes){
            ans+=1.0*Class[0]/Class[1];
        }
        return ans/n;
   }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi classes=makevvi("[[1,2],[3,5],[2,2]]");
    int extraStudents=2;
    auto ans=sol.maxAverageRatio(classes,extraStudents);
    DBG(ans);

    system("pause");
    return 0;
}
