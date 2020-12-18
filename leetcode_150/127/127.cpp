#include "utils.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>&wordList) {
        unordered_map<string,int>M;
        REP(i,wordList.size()){
            M[wordList[i]]=i;
        }
        if(!M.count(endWord))return 0;
        int end=M[endWord];
        if(!M.count(beginWord)){
            wordList.pb(beginWord);
            M[beginWord]=wordList.size()-1;
        }
        int begin=M[beginWord];
        int dis[wordList.size()];
        memset(dis,0x3f,sizeof(dis));
        queue<int>Q;
        dis[M[beginWord]]=1;
        Q.push(begin);
        M.erase(beginWord);
        while(Q.size()){
            int idx=Q.front();
            Q.pop();
            string s=wordList[idx];
            for(char&c:s){
                char temp=c;
                for(c='a';c<='z';c++){
                    if(M.count(s)){
                        dis[M[s]]=dis[idx]+1;
                        if(M[s]==end)return dis[M[s]];
                        Q.push(M[s]);
                        M.erase(s);
                    }
                }
                c=temp;
            }
        }
        return 0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string beginWord="hit";
    string endWord="cog";
    vector<string>wordList{"hot","dot","dog","lot","log","cog"};
    auto ans=sol.ladderLength(beginWord,endWord,wordList);
    DBG(ans);

    system("pause");
    return 0;
}
