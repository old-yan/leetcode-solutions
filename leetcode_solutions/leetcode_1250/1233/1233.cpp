#include "utils.h"

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(ALL(folder),[](string&x,string&y){return x.size()<y.size();});
        unordered_set<string>S;
        for(string&s:folder){
            int i=s.find('/',1);
            bool flag=true;
            while(i>=0){
                if(S.count(s.substr(0,i))){
                    flag=false;
                    break;
                }
                i=s.find('/',i+1);
            }
            if(flag)S.insert(s);
        }
        return vector<string>(ALL(S));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>folder{
        "/a","/a/b","/c/d","/c/d/e","/c/f"
    };
    auto ans=sol.removeSubfolders(folder);
    DBG(ans);

    system("pause");
    return 0;
}
