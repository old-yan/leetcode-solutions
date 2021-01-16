#include "utils.h"

class Solution {
    struct task{
        int p,c;
        task(int _p,int _c):p(_p),c(_c){}
    };
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        if(!k)return W;
        auto comp1=[&](task&x,task&y){
            return x.c>y.c;
        };
        auto comp2=[&](task&x,task&y){
            return x.p<y.p;
        };
        priority_queue<task,vector<task>,decltype(comp1)>Q1(comp1);
        priority_queue<task,vector<task>,decltype(comp2)>Q2(comp2);
        REP(i,Profits.size())Q1.push(task(Profits[i],Capital[i]));
        while(Q1.size()&&Q1.top().c<=W){
            Q2.push(Q1.top());
            Q1.pop();
        }
        while(Q2.size()){
            auto p=Q2.top();
            Q2.pop();
            W+=p.p;
            if(!--k)break;
            while(Q1.size()&&Q1.top().c<=W){
                Q2.push(Q1.top());
                Q1.pop();
            }
        }
        return W;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int k=2;
    int W=0;
    vi Profits{1,2,3};
    vi Capital{0,1,1};
    auto ans=sol.findMaximizedCapital(k,W,Profits,Capital);
    DBG(ans);

    system("pause");
    return 0;
}
