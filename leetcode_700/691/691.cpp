#include "utils.h"

class Solution {
    unordered_map<char,int>M;
    vi need;
    vvi material;
    int ans;
    void dfs(int cur,int curtake,vi&curhave,int curlack){
        if(curtake>=ans)return;
        if(cur<material.size()){
            int stillneed=0;
            REP(c,M.size()){
                if(curhave[c]<need[c]){
                    curlack-=min(material[cur][c],need[c]-curhave[c]);
                }
                curhave[c]+=material[cur][c];
                if(curhave[c]<need[c]&&material[cur][c])stillneed++;
            }
            if(!curlack)chmin(ans,curtake);
            else{
                if(stillneed)dfs(cur,curtake+1,curhave,curlack);
                FOR(i,cur+1,material.size()+1){
                    dfs(i,curtake+1,curhave,curlack);
                }
            }
            REP(c,M.size()){
                curhave[c]-=material[cur][c];
                if(curhave[c]<need[c]){
                    curlack+=min(material[cur][c],need[c]-curhave[c]);
                }
            }
        }
    }
public:
    int minStickers(vector<string>&stickers, string target) {
        for(char c:target){
            if(!M.count(c))M[c]=M.size();
        }
        need.resize(M.size(),0);
        for(char c:target)need[M[c]]++;
        {
            for(string&sticker:stickers){
                material.pb(vi(M.size(),0));
                for(char c:sticker)material.back()[M[c]]++;
            }
            vector<bool>isworse(stickers.size(),false);
            for(int i=stickers.size()-1;i>=0;i--){
                REP(j,stickers.size()){
                    if(j==i)continue;
                    bool advantage=false;
                    REP(c,M.size()){
                        if(!need[c])continue;
                        if(material[i][c]>material[j][c]){
                            advantage=true;
                        }
                    }
                    if(!advantage){
                        stickers.erase(stickers.begin()+i);
                        material.erase(material.begin()+i);
                        break;
                    }
                }
            }
            DBGV(stickers);
        }
        ans=target.size()+1;
        vi curhave(M.size(),0);
        REP(i,stickers.size()){
            dfs(i,1,curhave,accumulate(ALL(need),0));
        }
        return ans==target.size()+1?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>stickers{"with", "example", "science"};
    string target="thehat";
    auto ans=sol.minStickers(stickers,target);
    DBG(ans);

    system("pause");
    return 0;
}
