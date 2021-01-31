#include "utils.h"

class Solution {
    string code;
    bool istag(int&idx){
        if(code[idx]!='<')return false;
        int end=code.find_first_of('>',idx);
        if(end<0||end==idx+1||end>idx+10)return false;
        string tag=code.substr(idx+1,end-idx-1);
        for(char c:tag)if(!isupper(c))return false;
        end++;
        while(end+tag.size()+3<=code.size()){
            if(code[end]=='<'){
                if(code[end+1]=='/'){
                    if(code.substr(end+2,tag.size())==tag){
                        if(code[end+2+tag.size()]=='>'){
                            idx=end+3+tag.size();
                            return true;
                        }
                        else return false;
                    }
                    else return false;
                }
                else if(code[end+1]=='!'){
                    if(!isdata(end))return false;
                }
                else if(!istag(end))return false;
            }
            else end++;
        }
        return false;
    }
    bool isdata(int&idx){
        if(code.substr(idx,9)!="<![CDATA[")return false;
        int end;
        for(end=idx+9;end+3<=code.size();end++){
            if(code.substr(end,3)=="]]>")break;
        }
        if(end+3<=code.size()){
            idx=end+3;
            return true;
        }
        else return false;
    }
public:
    bool isValid(string _code) {
        int idx=0;
        code=_code;
        return istag(idx)&&idx==code.size();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string code="<DIV>This is the first line <A>  </A><B>    </B><![CDATA[<div>]]></DIV>";
    auto ans=sol.isValid(code);
    DBG(ans);

    system("pause");
    return 0;
}
