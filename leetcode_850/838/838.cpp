#include "utils.h"

class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<int>Q;
        int visit[dominoes.size()];
        memset(visit,0,sizeof(visit));
        int step=1;
        REP(i,dominoes.size()){
            if(dominoes[i]=='.'){
                if((i&&dominoes[i-1]=='R')||dominoes[i+1]=='L'){
                    visit[i]=step;
                    Q.push(i);
                }
            }
        }
        while(int l=Q.size()){
            step++;
            while(l--){
                auto p=Q.front();
                Q.pop();
                bool left=false,right=false;
                if(p&&dominoes[p-1]=='R'&&visit[p-1]!=step-1)left=true;
                if(dominoes[p+1]=='L'&&visit[p+1]!=step-1)right=true;
                if(left&&!right){
                    dominoes[p]='R';
                    if(dominoes[p+1]=='.'&&!visit[p+1]){
                        visit[p+1]=step;
                        Q.push(p+1);
                    }
                }
                else if(right&&!left){
                    dominoes[p]='L';
                    if(p&&dominoes[p-1]=='.'&&!visit[p-1]){
                        visit[p-1]=step;
                        Q.push(p-1);
                    }
                }
            }
        }
        return dominoes;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string dominoes=".L.R...LR..L..";
    auto ans=sol.pushDominoes(dominoes);
    DBG(ans);

    system("pause");
    return 0;
}
