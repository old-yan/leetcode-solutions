#include "utils.h"

class Solution {
public:
    string validIPAddress(string IP) {
        int num[128]={0};
        for(char c:IP)num[c]++;
        if(num[':']==7){
            int count=0;
            for(int i=0,j;i<IP.size();i=j+1){
                for(j=i;j<IP.size()&&IP[j]!=':';j++);
                if(j==i)return "Neither";
                string temp=IP.substr(i,j-i);
                if(temp.size()>4)return "Neither";
                for(char c:temp){
                    if(!isdigit(c)&&!(c>='a'&&c<='f')&&!(c>='A'&&c<='F'))return "Neither";
                }
                count++;
            }
            if(count==8)return "IPv6";
        }
        else if(num['.']==3){
            int count=0;
            for(int i=0,j;i<IP.size();i=j+1){
                for(j=i;j<IP.size()&&IP[j]!='.';j++);
                if(j==i)return "Neither";
                string temp=IP.substr(i,j-i);
                if(temp.size()>3)return "Neither";
                if(temp.size()>1&&temp[0]=='0')return "Neither";
                for(char c:temp)if(!isdigit(c))return "Neither";
                if(s2i(temp)>255)return "Neither";
                count++;
            }
            if(count==4)return "IPv4";
        }
        return "Neither";
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string IP="2001:0db8:85a3:0:0:8A2E:0370:7334";
    auto ans=sol.validIPAddress(IP);
    DBG(ans);

    system("pause");
    return 0;
}
