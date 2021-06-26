#include "utils.h"

class Solution {
    bool ban0[26]={0},used[10]={0};
    string all;
    vi w;
    vi maxAfter,minAfter;
    void init(vector<string>&words,string result){
        for(string&s:words){
            if(s.size()>1)ban0[s[0]-'A']=true;
            all+=s;
        }
        if(result.size()>1)ban0[result[0]-'A']=true;
        all+=result;
        sort(ALL(all));
        all.resize(unique(ALL(all))-all.begin());
        w.resize(all.size(),0);
        REP(i,all.size()){
            char c=all[i];
            for(string&s:words){
                REP(j,s.size()){
                    if(s[j]==c){
                        w[i]+=pow(10,s.size()-1-j);
                    }
                }
            }
            REP(j,result.size()){
                if(result[j]==c){
                    w[i]-=pow(10,result.size()-1-j);
                }
            }
        }
        vi idx(all.size());
        iota(ALL(idx),0);
        sort(ALL(idx),[&](int x,int y){return abs(w[x])>abs(w[y]);});
        auto _all=all;
        auto _w=w;
        REP(i,idx.size()){
            _all[i]=all[idx[i]];
            _w[i]=w[idx[i]];
        }
        all=_all;
        w=_w;
        maxAfter.resize(w.size(),0);
        minAfter.resize(w.size(),0);
        REPR(i,w.size()-1){
            if(i+1<w.size()){
                maxAfter[i]=maxAfter[i+1];
                minAfter[i]=minAfter[i+1];
            }
            if(w[i]>0)maxAfter[i]+=w[i]*10;
            else minAfter[i]+=w[i]*10;
        }
    }
    bool dfs(int idx,int cursum){
        if(idx==all.size())return !cursum;
        else{
            if(cursum+maxAfter[idx]<0||cursum+minAfter[idx]>0)return false;
            REP(i,10){
                if(!used[i]&&(i||!ban0[all[idx]-'A'])){
                    used[i]=true;
                    if(dfs(idx+1,cursum+w[idx]*i))return true;
                    used[i]=false;
                }
            }
        }
        return false;
    }
public:
    bool isSolvable(vector<string>& words, string result) {
        init(words,result);
        return dfs(0,0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{"THIS","IS","TOO"};
    string result="FUNNY";
    auto ans=sol.isSolvable(words,result);
    DBG(ans);

    system("pause");
    return 0;
}
