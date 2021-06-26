#include "utils.h"

class Solution {
public:
    string entityParser(string text) {
        string ans;
        for(int i=0;i<text.size();){
            if(text[i]!='&')ans+=text[i++];
            else{
                if(text[i+1]=='g'&&text[i+2]=='t'&&text[i+3]==';'){
                    ans+='>';
                    i+=4;
                }
                else if(text[i+1]=='l'&&text[i+2]=='t'&&text[i+3]==';'){
                    ans+='<';
                    i+=4;
                }
                else if(text[i+1]=='a'&&text[i+2]=='m'&&text[i+3]=='p'&&text[i+4]==';'){
                    ans+='&';
                    i+=5;
                }
                else if(text[i+1]=='q'&&text[i+2]=='u'&&text[i+3]=='o'&&text[i+4]=='t'&&text[i+5]==';'){
                    ans+='"';
                    i+=6;
                }
                else if(text[i+1]=='a'&&text[i+2]=='p'&&text[i+3]=='o'&&text[i+4]=='s'&&text[i+5]==';'){
                    ans+='\'';
                    i+=6;
                }
                else if(text[i+1]=='f'&&text[i+2]=='r'&&text[i+3]=='a'&&text[i+4]=='s'&&text[i+5]=='l'&&text[i+6]==';'){
                    ans+='/';
                    i+=7;
                }
                else ans+=text[i++];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string text="&amp; is an HTML entity but &ambassador; is not.";
    auto ans=sol.entityParser(text);
    DBG(ans);

    system("pause");
    return 0;
}
