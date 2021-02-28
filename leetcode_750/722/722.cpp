#include "utils.h"

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool signal=false;
        vector<string>ans;
        for(string&line:source){
            if(!signal)ans.pb({});
            while(true){
                if(signal){
                    size_t i=line.find("*/");
                    if(i<line.size()){
                        line=line.substr(i+2);
                        signal=false;
                    }
                    else break;
                }
                else{
                    size_t i1=line.find("/*");
                    size_t i2=line.find("//");
                    if(i1<i2){
                        ans.back()+=line.substr(0,i1);
                        line=line.substr(i1+2);
                        signal=true;
                    }
                    else{
                        ans.back()+=line.substr(0,i2);
                        break;
                    }
                }
            }
            if(ans.back().empty())ans.erase(prev(ans.end()));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>source{"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
    auto ans=sol.removeComments(source);
    DBGV(ans);

    system("pause");
    return 0;
}
