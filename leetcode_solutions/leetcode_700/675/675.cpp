#include "utils.h"

class Solution {
    struct triple{
        int i,j,k;
        triple(){}
        triple(int _i,int _j,int _k):i(_i),j(_j),k(_k){}
    };
    triple Q[3000];
    int h,t;
    int mindis[50][50];
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m=forest.size(),n=forest[0].size();
        auto comp=[](triple&x,triple&y){
            return x.k<y.k;
        };
        vector<triple>woods;
        REP(i,m){
            REP(j,n){
                if(forest[i][j]>1){
                    woods.emplace_back(i,j,forest[i][j]);
                }
            }
        }
        sort(ALL(woods),comp);
        int i=0,j=0;
        int ans=0;
        for(auto wood:woods){
            h=t=0;
            memset(mindis,0x3f,sizeof(mindis));
            mindis[i][j]=0;
            Q[t++]={i,j,0};
            while(h<t){
                auto q=Q[h++];
                q.k++;
                REP(k,4){
                    int ii=q.i+di[k],jj=q.j+dj[k];
                    if(VALID&&forest[ii][jj]&&chmin(mindis[ii][jj],q.k)){
                        Q[t++]={ii,jj,q.k};
                    }
                }
                if(mindis[wood.i][wood.j]!=0x3f3f3f3f)break;
            }
            if(mindis[wood.i][wood.j]==0x3f3f3f3f)return -1;
            ans+=mindis[wood.i][wood.j];
            i=wood.i,j=wood.j;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi forest{
        {7339,0},
        {191,4835},
        {2529,0},
        {966,4605},
        {6704,0},
        {7947,0},
        {3280,7050},
        {0,7140},
        {9103,2678}
    };
    auto ans=sol.cutOffTree(forest);
    DBG(ans);

    system("pause");
    return 0;
}
