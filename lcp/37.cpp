#include "utils.h"

class Solution {
    struct line{
        double k,b;
        line(int _k,int _b):k(_k),b(_b){}
    };
    double maxdx(vector<line>&v){
        map<double,vector<double>>M;
        REP(i,v.size())M[v[i].k].pb(v[i].b);
        double Min=1000000000,Max=-1000000000;
        auto keep=[&](double val){
            chmin(Min,val);
            chmax(Max,val);
        };
        for(auto it=M.begin();it!=M.end();++it){
            sort(ALL(it->second));
            if(it!=M.begin()){
                auto it2=prev(it);
                keep(double(it->second.back()-it2->second.front())/(it->first-it2->first));
                keep(double(it->second.back()-it2->second.back())/(it->first-it2->first));
                keep(double(it->second.front()-it2->second.front())/(it->first-it2->first));
                keep(double(it->second.front()-it2->second.back())/(it->first-it2->first));
            }
        }
        return max(0.,Max-Min);
    }
public:
    double minRecSize(vector<vector<int>>& lines) {
        vector<line>v;
        for(auto&l:lines){
            v.emplace_back(l[0],l[1]);
        }
        double dx=maxdx(v);
        for(auto&l:v){
            l.b/=-l.k;
            l.k=1/l.k;
        }
        double dy=maxdx(v);
        return dx*dy;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi lines=makevvi("[[2,3],[3,0],[4,1]]");
    auto ans=sol.minRecSize(lines);
    DBG(ans);

    system("pause");
    return 0;
}
