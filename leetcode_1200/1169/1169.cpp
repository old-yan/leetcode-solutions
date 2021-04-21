#include "utils.h"

class Solution {
    struct node{
        string name;
        int time,amount;
        string city;
        node(){}
        node(const string&t){
            auto v=split(t,',');
            name=v[0];
            time=s2i(v[1]);
            amount=s2i(v[2]);
            city=v[3];
        }
    };
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n=transactions.size();
        node a[n];
        T.set(0);
        REP(i,n){
            a[i]=node(transactions[i]);
            T.step_forward(a[i].time);
        }
        vector<string>ans;
        REP(i,n){
            if(a[i].amount>1000)ans.pb(transactions[i]);
            else{
                REP(j,n){
                    if(a[i].name==a[j].name&&a[i].city!=a[j].city&&abs(a[i].time-a[j].time)<=60){
                        ans.pb(transactions[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>transactions{
        "alice,20,800,mtv","alice,50,100,beijing"
    };
    auto ans=sol.invalidTransactions(transactions);
    DBGV(ans);

    system("pause");
    return 0;
}
