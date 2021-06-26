#include "Trie.h"
#include "utils.h"

StaticTrie T;
class Solution {
    vector<string>buckets[101];
    int maxarea=0;
    vector<string>ans,path;
    void test(int i,vi&cursor,int n){
        bool end=buckets[i].size();
        if(end){
            REP(j,n)if(T[cursor[j]][26]<0){
                end=false;
                break;
            }
        }
        if(end&&chmax(maxarea,int((i+1)*n)))ans=path;
        for(string&s:buckets[n]){
            bool can=true;
            REP(j,n){
                if(!T[cursor[j]][s[j]-'a']){
                    can=false;
                    break;
                }
            }
            if(!can)continue;
            path.pb(s);
            vi nxt(n);
            REP(j,n){
                nxt[j]=T[cursor[j]][s[j]-'a'];
            }
            test(i+1,nxt,n);
            path.pop_back();
        }
    }
public:
    vector<string> maxRectangle(vector<string>& words) {
        T.clear();
        int maxlen=0;
        for(string&s:words){
            T.insert(s);
            buckets[s.size()].pb(s);
            chmax(maxlen,int(s.size()));
        }
        REPR(n,100)if(buckets[n].size()&&n*maxlen>maxarea){
            vi cursor(n,0);
            test(0,cursor,n);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{
        "this", "real", "hard", "trh", "hea", "iar", "sld"
    };
    auto ans=sol.maxRectangle(words);
    DBGV(ans);

    system("pause");
    return 0;
}
