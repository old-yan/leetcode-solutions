#include "utils.h"

class Solution {
    struct node{
        int num;
        char ch;
        node(int _num,char _ch):num(_num),ch(_ch){}
    };
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="##";
        node*aa=new node(a,'a');
        node*bb=new node(b,'b');
        node*cc=new node(c,'c');
        vector<node*>v{aa,bb,cc};
        while(true){
            sort(ALL(v),[](node*x,node*y){return x->num>y->num;});
            if(!v[0]->num)break;
            if(ans[ans.size()-2]==v[0]->ch&&ans.back()==v[0]->ch){
                if(!v[1]->num)break;
                v[1]->num--;
                ans+=v[1]->ch;
            }
            else{
                v[0]->num--;
                ans+=v[0]->ch;
            }
        }
        return ans.substr(2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int a=1;
    int b=1;
    int c=7;
    auto ans=sol.longestDiverseString(a,b,c);
    DBG(ans);

    system("pause");
    return 0;
}
