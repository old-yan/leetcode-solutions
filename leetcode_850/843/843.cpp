#include "utils.h"

class Master {
    const string&secret;
    const vector<string>&wordlist;
    int life=10;
public:
    Master(const string&_secret,const vector<string>&_wordlist):secret(_secret),wordlist(_wordlist){}
    int guess(string word){
        if(!life--){
            cout<<"no life\n";
            system("pause");
        }
        for(auto&s:wordlist){
            if(s==word){
                int same=0;
                REP(i,6){
                    if(secret[i]==word[i])same++;
                }
                if(same==6)cout<<"life cost="<<10-life<<endl;
                return same;
            }
        }
        return -1;
    }
};

class Solution {
    int getSame(string&word1,string&word2){
        int same=0;
        REP(i,6){
            if(word1[i]==word2[i])same++;
        }
        return same;
    }
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        while(wordlist.size()>1){
            int n=wordlist.size();
            int maxSameCnt[n];
            memset(maxSameCnt,0,sizeof(maxSameCnt));
            vi sameCnt[n][6];
            REP(i,n){
                REP(j,i){
                    int same=getSame(wordlist[i],wordlist[j]);
                    sameCnt[i][same].emplace_back(j);
                    chmax(maxSameCnt[i],int(sameCnt[i][same].size()));
                    sameCnt[j][same].emplace_back(i);
                    chmax(maxSameCnt[j],int(sameCnt[j][same].size()));
                }
            }
            int a=min_element(maxSameCnt,maxSameCnt+n)-maxSameCnt;
            int res=master.guess(wordlist[a]);
            int idx=0;
            for(int b:sameCnt[a][res]){
                wordlist[idx++]=wordlist[b];
            }
            wordlist.resize(idx);
        }
        master.guess(wordlist[0]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string secret="cymplm";
    vector<string>wordlist{"eykdft","gjeixr","eksbjm","mxqhpk","tjplhf","ejgdra","npkysm","jsrsid","cymplm","vegdgt","jnhdvb","jdhlzb","sgrghh","jvydne","laxvnm","xbcliw","emnfcw","pyzdnq","vzqbuk","gznrnn","robxqx","oadnrt","kzwyuf","ahlfab","zawvdf","edhumz","gkgiml","wqqtla","csamxn","bisxbn","zwxbql","euzpol","mckltw","bbnpsg","ynqeqw","uwvqcg","hegrnc","rrqhbp","tpfmlh","wfgfbe","tpvftd","phspjr","apbhwb","yjihwh","zgspss","pesnwj","dchpxq","axduwd","ropxqf","gahkbq","yxudiu","dsvwry","ecfkxn","hmgflc","fdaowp","hrixpl","czkgyp","mmqfao","qkkqnz","lkzaxu","cngmyn","nmckcy","alpcyy","plcmts","proitu","tpzbok","vixjqn","suwhab","dqqkxg","ynatlx","wmbjxe","hynjdf","xtcavp","avjjjj","fmclkd","ngxcal","neyvpq","cwcdhi","cfanhh","ruvdsa","pvzfyx","hmdmtx","pepbsy","tgpnql","zhuqlj","tdrsfx","xxxyle","zqwazc","hsukcb","aqtdvn","zxbxps","wziidg","tsuxvr","florrj","rpuorf","jzckev","qecnsc","rrjdyh","zjtdaw","dknezk"};
    Master master(secret,wordlist);
    sol.findSecretWord(wordlist,master);

    system("pause");
    return 0;
}
