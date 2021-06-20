#include "utils.h"

class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        int m=docs.size();
        for(auto&row:docs)sort(ALL(row));
        int join_mat[m][500];
        auto get_join_mat=[&](){
            priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>Q;
            REP(i,m)Q.emplace(docs[i][0],i,0);
            while(Q.size()){
                auto curmin=get<0>(Q.top());
                vi currows;
                while(Q.size()&&get<0>(Q.top())==curmin){
                    auto [val,i,j]=Q.top();
                    Q.pop();
                    currows.pb(i);
                    if(j+1<docs[i].size())Q.emplace(docs[i][j+1],i,j+1);
                }
                REP(i,currows.size()){
                    REP(j,i){
                        join_mat[currows[j]][currows[i]]++;
                    }
                }
            }
        };
        memset(join_mat,0,sizeof(join_mat));
        get_join_mat();
        vector<string>ans;
        REP(i,m){
            REP(j,i){
                int join=join_mat[j][i];
                if(join){
                    static char c[20];
                    sprintf(c,"%d,%d: %.4f",j,i,1.0*join/(docs[i].size()+docs[j].size()-join)+1e-9);
                    ans.pb(c);
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi docs=makevvi("[[14, 15, 100, 9, 3], [32, 1, 9, 3, 5], [15, 29, 2, 6, 8, 7], [7, 10]]");
    auto ans=sol.computeSimilarities(docs);
    DBGV(ans);

    system("pause");
    return 0;
}
