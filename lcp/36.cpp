#include "utils.h"

class Solution {
    void fill(vvi&v){
        for(auto&_:v)::fill(ALL(_),0x80808080);
    }
public:
    int maxGroupNumber(vector<int>& tiles) {
        sort(ALL(tiles));
        int n=tiles.size();
        vvi pre(5,vi(5)),cur(pre);
        int preval=-1,prenum,ans=0;
        for(int i=0,j;i<n;i=j){
            for(j=i+1;j<n&&tiles[j]==tiles[i];j++);
            int curval=tiles[i],curnum=j-i;
            if(!i||tiles[i]!=tiles[i-1]+1){
                fill(pre);
                pre[0][0]=ans;
                prenum=0;
            }
            fill(cur);
            int A=min(4,curnum),B=min({A,4,prenum});
            REPR(a,A){
                REPR(b,B){
                    REPR(c,min({2,int(curnum-a),int(B-b)})){
                        chmax(cur[a][b],pre[b+c][c]+int(c)+int(curnum-a-c)/3);
                    }
                    if(b<B)chmax(cur[a][b],cur[a][b+1]);
                    if(a<A)chmax(cur[a][b],cur[a+1][b]);
                    chmax(ans,cur[a][b]);
                }
            }
            pre=cur,preval=curval,prenum=curnum;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi tiles{4,5,6,7,8,9,10,11,11};
    auto ans=sol.maxGroupNumber(tiles);
    DBG(ans);

    system("pause");
    return 0;
}
