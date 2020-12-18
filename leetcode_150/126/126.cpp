#include "utils.h"

class Solution {
    string beginWord,endWord;
    vector<string>wordList;
    int begin,end;
    vector<vector<string>>ans;
    void dfs(int cur,vector<int>&path,vector<int>trace[]){
        path.pb(cur);
        if(cur==begin){
            vector<string>temp;
            REPR(i,path.size()-1)temp.pb(wordList[path[i]]);
            ans.pb(temp);
        }
        else{
            for(int a:trace[cur])dfs(a,path,trace);
        }
        path.pop_back();
    }
public:
    vector<vector<string>> findLadders(string _beginWord, string _endWord, vector<string>&_wordList) {
        beginWord=_beginWord;
        endWord=_endWord;
        wordList=_wordList;
        unordered_map<string,int>M;
        REP(i,wordList.size()){
            M[wordList[i]]=i;
        }
        if(!M.count(endWord))return ans;
        end=M[endWord];
        if(!M.count(beginWord)){
            wordList.pb(beginWord);
            M[beginWord]=begin=wordList.size()-1;
        }
        else begin=M[beginWord];
        int dis[wordList.size()];
        vector<int>trace[wordList.size()];
        memset(dis,0x3f,sizeof(dis));
        queue<int>Q;
        dis[begin]=0;
        Q.push(begin);
        while(Q.size()){
            int idx=Q.front();
            Q.pop();
            if(idx==end)break;
            string s=wordList[idx];
            M.erase(s);
            for(char&c:s){
                char temp=c;
                for(c='a';c<='z';c++){
                    if(c!=temp&&M.count(s)){
                        if(dis[idx]+1<dis[M[s]]){
                            dis[M[s]]=dis[idx]+1;
                            trace[M[s]].pb(idx);
                            Q.push(M[s]);
                        }
                        else if(dis[idx]+1==dis[M[s]]){
                            trace[M[s]].pb(idx);
                        }
                    }
                }
                c=temp;
            }
        }
        vector<int>path;
        dfs(M[endWord],path,trace);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string beginWord="hit";
    string endWord="cog";
    vector<string>wordList{"hot","dot","dog","lot","log","cog"};
    auto ans=sol.findLadders(beginWord,endWord,wordList);
    DBGVV(ans);

    system("pause");
    return 0;
}
