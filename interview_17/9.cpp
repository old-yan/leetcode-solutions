#include "utils.h"

class Solution {
    struct node{
        int ratio,cursor,res;
        node(int _ratio):ratio(_ratio){}
        bool operator<(const node&other)const{
            return res>other.res;
        }
    };
public:
    int getKthMagicNumber(int k) {
        static int seq[650]={0};
        if(!seq[0]){
            int len=1;
            seq[0]=1;
            node a(3);
            a.cursor=0,a.res=seq[a.cursor]*a.ratio;
            node b(5);
            b.cursor=0,b.res=seq[b.cursor]*b.ratio;
            node c(7);
            c.cursor=0,c.res=seq[c.cursor]*c.ratio;
            priority_queue<node>Q;
            Q.push(a),Q.push(b),Q.push(c);
            while(len<650){
                auto p=Q.top();
                Q.pop();
                if(p.res>seq[len-1]){
                    seq[len++]=p.res;
                }
                p.res=seq[++(p.cursor)]*p.ratio;
                Q.push(p);
            }
        }
        return seq[k-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int k=5;
    auto ans=sol.getKthMagicNumber(k);
    DBG(ans);

    system("pause");
    return 0;
}
