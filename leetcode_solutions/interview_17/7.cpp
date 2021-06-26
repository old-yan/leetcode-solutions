#include "utils.h"

Union u(300000);
class Solution {
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        u.reset();
        unordered_map<string,int>idmap;
        vector<string>namelist;
        vector<int>name_num;
        vector<pair<int,int>>name_name;
        REP(i,names.size()){
            names[i].pop_back();
            int j=names[i].find('(');
            namelist.pb(names[i].substr(0,j));
            name_num.emplace_back(s2i(names[i].substr(j+1)));
            idmap[namelist.back()]=i;
        }
        for(string&s:synonyms){
            s.pop_back();
            int j=s.find(',');
            string a=s.substr(1,j-1);
            string b=s.substr(j+1);
            if(!idmap.count(a)){
                namelist.pb(a);
                idmap[a]=idmap.size();
            }
            if(!idmap.count(b)){
                namelist.pb(b);
                idmap[b]=idmap.size();
            }
            name_name.emplace_back(idmap[a],idmap[b]);
        }
        for(auto [a,b]:name_name){
            u.unite(a,b);
        }
        REP(i,namelist.size()){
            int j=u.Find(i);
            if(j==i)continue;
            chmin(namelist[j],namelist[i]);
            if(i<name_num.size()){
                name_num[j]+=name_num[i];
            }
        }
        vector<string>ans;
        REP(i,name_num.size()){
            int j=u.Find(i);
            if(j!=i)continue;
            ans.pb(namelist[i]+'('+i2s(name_num[i])+')');
        }
        sort(ALL(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>names{
        "John(15)","Jon(12)","Chris(13)","Kris(4)","Christopher(19)"
    };
    vector<string>synonyms{
        "(Jon,John)","(John,Johnny)","(Chris,Kris)","(Chris,Christopher)"
    };
    auto ans=sol.trulyMostPopular(names,synonyms);
    DBGV(ans);

    system("pause");
    return 0;
}
