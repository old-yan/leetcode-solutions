#include "utils.h"

class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.size()==1)return i2s(s2i(n)-1);
        if(int(n.find_first_not_of('9',0))<0)return i2s(s2i(n)+2);
        if(n[0]=='1'&&int(n.find_first_not_of('0',1))<0)return i2s(s2i(n)-1);
        if(n[0]=='1'&&n.back()=='1'&&n.find_first_not_of('0',1)==n.size()-1)return i2s(s2i(n)-2);
        string half=n.substr(0,(n.size()+1)/2);
        string ans;
        ll dis=LLONG_MAX;
        if(half.size()==i2s(s2i(half)-1).size()){
            string temp=i2s(s2i(half)-1);
            string temp2=temp.substr(0,n.size()/2);
            reverse(ALL(temp2));
            temp+=temp2;
            auto val=s2i(temp);
            if(chmin(dis,abs(s2i(n)-val))){
                ans=temp;
            }
        }
        if(!isPolindromic(ALL(n))){
            string temp=i2s(s2i(half));
            string temp2=temp.substr(0,n.size()/2);
            reverse(ALL(temp2));
            temp+=temp2;
            auto val=s2i(temp);
            if(chmin(dis,abs(s2i(n)-val))){
                ans=temp;
            }
        }
        if(half.size()==i2s(s2i(half)+1).size()){
            string temp=i2s(s2i(half)+1);
            string temp2=temp.substr(0,n.size()/2);
            reverse(ALL(temp2));
            temp+=temp2;
            auto val=s2i(temp);
            if(chmin(dis,abs(s2i(n)-val))){
                ans=temp;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string n="123";
    auto ans=sol.nearestPalindromic(n);
    DBG(ans);

    system("pause");
    return 0;
}
