#include "utils.h"

class Solution {
    int ratio[1000];
    void getRatio(string&formula){
        stack<int>S;
        for(int i=0;i<formula.size();i++){
            if(formula[i]=='(')S.push(i);
            else if(formula[i]==')'){
                int r=0;
                if(!isdigit(formula[i+1]))r=1;
                else{
                    for(int j=i+1;isdigit(formula[j]);j++)r=r*10+formula[j]-'0';
                }
                ratio[S.top()]=r;
                S.pop();
            }
        }
    }
public:
    string countOfAtoms(string formula) {
        getRatio(formula);
        stack<int>S;
        long curratio=1;
        map<string,int>M;
        for(int i=0;i<formula.size();){
            if(formula[i]=='('){
                S.push(ratio[i]);
                curratio*=ratio[i];
                i++;
            }
            else if(formula[i]==')'){
                curratio/=S.top();
                S.pop();
                while(isdigit(formula[++i]));
            }
            else{
                string elem=formula.substr(i,1);
                while(islower(formula[++i]))elem+=formula[i];
                if(!isdigit(formula[i]))M[elem]+=curratio;
                else{
                    int r=0;
                    while(isdigit(formula[i]))r=r*10+formula[i++]-'0';
                    M[elem]+=curratio*r;
                }
            }
        }
        string ans;
        for(auto&it:M){
            ans+=it.first;
            if(it.second>1)ans+=i2s(it.second);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string formula="Mg(OH)2";
    auto ans=sol.countOfAtoms(formula);
    DBG(ans);

    system("pause");
    return 0;
}
