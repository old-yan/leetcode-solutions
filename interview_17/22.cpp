#include "utils.h"

class Solution {
    string beginWord,endWord;
    vector<string>wordList;
    int begin,end;
public:
    vector<string> findLadders(string _beginWord, string _endWord, vector<string>&_wordList) {
        beginWord=_beginWord;
        endWord=_endWord;
        wordList=_wordList;
        unordered_map<string,int>M;
        for(int i=0;i<wordList.size();i++){
            M[wordList[i]]=i;
        }
        if(!M.count(endWord))return {};
        end=M[endWord];
        if(!M.count(beginWord)){
            wordList.push_back(beginWord);
            M[beginWord]=begin=wordList.size()-1;
        }
        else begin=M[beginWord];
        int dis[wordList.size()];
        vector<int>trace(wordList.size(),-1);
        memset(dis,0x3f,sizeof(dis));
        queue<int>Q;
        dis[begin]=0;
        M.erase(wordList[begin]);
        Q.push(begin);
        while(Q.size()){
            int idx=Q.front();
            Q.pop();
            if(idx==end)break;
            string s=wordList[idx];
            for(char&c:s){
                char temp=c;
                for(c='a';c<='z';c++){
                    if(c!=temp&&M.count(s)){
                        if(dis[idx]+1<dis[M[s]]){
                            dis[M[s]]=dis[idx]+1;
                            trace[M[s]]=idx;
                            Q.push(M[s]);
                        }
                        else if(dis[idx]+1==dis[M[s]]){
                            trace[M[s]]=idx;
                        }
                    }
                }
                c=temp;
            }
        }
        if(trace[end]<0)return {};
        vector<string>path;
        int cur=end;
        while(cur>=0){
            path.pb(wordList[cur]);
            cur=trace[cur];
        }
        reverse(ALL(path));
        return path;
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
    DBGV(ans);

    system("pause");
    return 0;
}
