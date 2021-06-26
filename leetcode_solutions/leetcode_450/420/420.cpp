#include "utils.h"

class Solution {
public:
    int strongPasswordChecker(string password) {
        bool lower=false,upper=false,digit=false;
        for(char c:password){
            if(islower(c))lower=true;
            else if(isupper(c))upper=true;
            else if(isdigit(c))digit=true;
        }
        int absent=3-lower-upper-digit;
        if(password.size()<=4)return 6-password.size();
        if(password.size()==5){
            if(absent<=1)return 1;
            else return 2;
        }
        int modify=0,del=0;
        auto comp=[&](int x,int y){
            if(x<3)return true;
            if(y<3)return false;
            return x%3>y%3||(x%3==y%3&&x>y);
        };
        priority_queue<int,vector<int>,decltype(comp)>Q(comp);
        for(int i=0,j;i<password.size();i=j){
            for(j=i+1;password[j]==password[i];j++);
            int l=j-i;
            Q.emplace(l);
        }
        int l=password.size();
        while(l>20){
            auto i=Q.top();
            Q.pop();
            if(i<3){
                del+=l-20;
                break;
            }
            del++;
            l--;
            Q.push(i-1);
        }
        while(Q.size()&&Q.top()>=3){
            modify+=Q.top()/3;
            Q.pop();
        }
        chmax(modify,absent);
        return del+modify;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string password="bbaaaaaaaaaaaaaaacccccc";
    auto ans=sol.strongPasswordChecker(password);
    DBG(ans);

    system("pause");
    return 0;
}
