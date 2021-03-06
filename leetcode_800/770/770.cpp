#include "utils.h"

class Solution {
    struct node{
        const static int N=13;
        int coef;
        int expo[N];
        int sum;
        node():coef(0){memset(expo,0,sizeof(expo));};
        node(int _coef):coef(_coef){memset(expo,0,sizeof(expo));};
        node operator*(const node&other)const{
            node a(coef*other.coef);
            REP(i,N)a.expo[i]=expo[i]+other.expo[i];
            return a;
        }
        bool operator<(const node&other)const{
            if(sum!=other.sum)return sum>other.sum;
            REP(i,N)if(expo[i]!=other.expo[i])return expo[i]>other.expo[i];
            return false;
        }
    };
    string to_string(node&n){
        string s=i2s(n.coef);
        REP(i,node::N)REP(j,n.expo[i])s+="*"+unknown_list[i];
        return s;
    }
    unordered_map<string,int>known;
    set<string>S;
    unordered_map<string,int>unknown;
    vector<string>unknown_list;
    vector<node>fun(string&expression,int&idx){
        if(expression[idx]=='('){
            idx++;
            vector<node>v;
            bool signal=true;
            while(true){
                auto res=fun(expression,idx);
                while(expression[idx]=='*'){
                    idx++;
                    auto nxt=fun(expression,idx);
                    vector<node>tmp;
                    for(auto&a:res)for(auto&b:nxt)tmp.pb(a*b);
                    res.swap(tmp);
                }
                if(!signal)for(auto&a:res)a.coef*=-1;
                v.insert(v.end(),ALL(res));
                if(expression[idx]==')'){
                    idx++;
                    return v;
                }
                signal=expression[idx++]=='+';
            }
        }
        else if(isdigit(expression[idx])){
            int val=0;
            while(isdigit(expression[idx])){
                val=val*10+expression[idx++]-'0';
            }
            return {node(val)};
        }
        else{
            string s;
            while(islower(expression[idx])){
                s+=expression[idx++];
            }
            if(known.count(s))return {node(known[s])};
            else{
                node a(1);
                a.expo[unknown[s]]=1;
                return {a};
            }
        }
    }
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        expression.erase(remove(ALL(expression),' '),expression.end());
        REP(i,evalvars.size())known[evalvars[i]]=evalints[i];
        for(int i=0,j;i<expression.size();){
            if(islower(expression[i])){
                for(j=i+1;islower(expression[j]);j++);
                string s=expression.substr(i,j-i);
                if(!known.count(s))S.insert(s);
                i=j;
            }
            else i++;
        }
        for(auto&s:S){
            unknown[s]=unknown.size();
            unknown_list.pb(s);
        }
        int M=unknown_list.size();
        int idx=0;
        expression='('+expression+')';
        auto nodes=fun(expression,idx);
        for(auto&a:nodes)a.sum=accumulate(a.expo,a.expo+M,0);
        auto same=[&](node&x,node&y){
            if(x.sum!=y.sum)return false;
            REP(i,M)if(x.expo[i]!=y.expo[i])return false;
            return true;
        };
        vector<string>ans;
        sort(ALL(nodes));
        for(int i=0,j;i<nodes.size();i=j){
            for(j=i+1;j<nodes.size()&&same(nodes[j],nodes[i]);j++){
                nodes[i].coef+=nodes[j].coef;
            }
            if(nodes[i].coef){
                ans.pb(to_string(nodes[i]));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string expression="e + 8 - a + 5";
    vector<string>evalvars{"e"};
    vi evalints{1};
    auto ans=sol.basicCalculatorIV(expression,evalvars,evalints);
    DBGV(ans);

    system("pause");
    return 0;
}
