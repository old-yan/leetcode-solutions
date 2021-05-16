#include "Union.h"
#include "utils.h"

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        Union u(n);
        for(auto&allow:allowedSwaps){
            u.unite(allow[0],allow[1]);
        }
        vi v[n];
        REP(i,n)v[u.Find(i)].pb(i);
        int same=0;
        REP(i,n){
            if(v[i].size()){
                vi v1,v2;
                for(int a:v[i]){
                    v1.pb(source[a]);
                    v2.pb(target[a]);
                }
                sort(ALL(v1));
                sort(ALL(v2));
                for(int i=0,j=0;i<v1.size()&&j<v2.size();){
                    if(v1[i]<v2[j])i++;
                    else if(v1[i]>v2[j])j++;
                    else{
                        same++,i++,j++;
                    }
                }
            }
        }
        return n-same;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi source{1,2,3,4};
    vi target{2,1,4,5};
    vvi allowedSwaps=makevvi("[[0,1],[2,3]]");
    auto ans=sol.minimumHammingDistance(source,target,allowedSwaps);
    DBG(ans);

    system("pause");
    return 0;
}
