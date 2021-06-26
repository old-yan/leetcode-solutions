#include "utils.h"

class Solution {
    unordered_map<string,int>M;
    bool iszero[40]={0};
    double matrix[40][40];
    vi v[40];
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        Union u(40);
        REP(i,40)REP(j,40)matrix[i][j]=-1;
        REP(i,equations.size()){
            auto&A=equations[i];
            if(!M.count(A[0]))M[A[0]]=M.size();
            if(!M.count(A[1]))M[A[1]]=M.size();
            if(values[i]){
                matrix[M[A[0]]][M[A[1]]]=values[i];
                matrix[M[A[1]]][M[A[0]]]=1/values[i];
                u.unite(M[A[0]],M[A[1]]);
                v[M[A[0]]].pb(M[A[1]]);
                v[M[A[1]]].pb(M[A[0]]);
            }
            else{
                iszero[M[A[0]]]=true;
            }
        }
        vector<double>ans(queries.size());
        REP(i,queries.size()){
            auto&A=queries[i];
            if(!M.count(A[0]))ans[i]=-1;
            else if(iszero[M[A[0]]])ans[i]=0;
            else if(!M.count(A[1]))ans[i]=-1;
            else if(!u.same(M[A[0]],M[A[1]]))ans[i]=-1;
            else if(A[0]==A[1])ans[i]=1;
            else{
                bool visited[40]={0};
                queue<pair<int,double>>Q;
                Q.emplace(M[A[0]],1);
                visited[M[A[0]]]=true;
                while(Q.size()){
                    auto a=Q.front();
                    Q.pop();
                    for(int b:v[a.first]){
                        if(!visited[b]){
                            visited[b]=true;
                            if(b==M[A[1]]){
                                ans[i]=a.second*matrix[a.first][b];
                                break;
                            }
                            Q.emplace(b,a.second*matrix[a.first][b]);
                        }
                    }
                    if(visited[M[A[1]]])break;
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

    vector<vector<string>> equations ={{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> values = {1.5,2.5,5.0};
    vector<vector<string>> queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    auto ans=sol.calcEquation(equations,values,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
