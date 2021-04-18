#include "utils.h"

class Solution {
    int m=1000000,n=1000000;
    set<pair<int,int>>S;
    int test(int i,int j,int targeti,int targetj){
        set<pair<int,int>>visited;
        visited.emplace(i,j);
        queue<pair<int,int>>Q({{i,j}});
        int end=S.size()*(S.size()-1)/2;
        while(Q.size()&&visited.size()<=end){
            auto [i,j]=Q.front();
            Q.pop();
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(!VALID)continue;
                if(!S.count({ii,jj})&&visited.emplace(ii,jj).second){
                    Q.emplace(ii,jj);
                }
            }
        }
        if(visited.count({targeti,targetj}))return 2;
        else if(visited.size()>end)return 1;
        else return 0;
    }
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for(auto&bl:blocked)S.emplace(bl[0],bl[1]);
        int res1=test(source[0],source[1],target[0],target[1]);
        if(res1==2)return true;
        if(!res1)return false;
        int res2=test(target[0],target[1],source[0],source[1]);
        return res2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi blocked=makevvi("[[0,1],[1,0]]");
    vi source{0,0};
    vi target{0,2};
    auto ans=sol.isEscapePossible(blocked,source,target);
    DBG(ans);

    system("pause");
    return 0;
}
