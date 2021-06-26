#include "utils.h"

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int>M;
        for(string&s:names){
            if(M.count(s)){
                int v=M[s]+1;
                string temp;
                while(true){
                    temp=s+'('+i2s(v)+')';
                    if(M.count(temp))v++;
                    else break;
                }
                M[s]=v;
                s.swap(temp);
                M[s]=0;
            }
            else M[s]=0;
        }
        return names;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>names{
        "pes","fifa","gta","pes(2019)"
    };
    auto ans=sol.getFolderNames(names);
    DBGV(ans);

    system("pause");
    return 0;
}
