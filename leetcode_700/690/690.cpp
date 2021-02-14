#include "Employee.h"
#include "utils.h"

class Solution {
    int id2idx[2001];
    int fun(vector<Employee*> employees,int id){
        int cnt=0;
        for(int subordinate:employees[id2idx[id]]->subordinates){
            cnt+=fun(employees,subordinate);
        }
        return employees[id2idx[id]]->importance+cnt;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        REP(i,employees.size()){
            id2idx[employees[i]->id]=i;
        }
        return fun(employees,id);
    }
};
int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<Employee>_employees{
        {1,2,{2}},
        {2,3,{}},
        {3,3,{}},
    };
    vector<Employee*>employees;
    REP(i,_employees.size())employees.pb(&_employees[i]);
    int id=1;
    auto ans=sol.getImportance(employees,id);


    system("pause");
    return 0;
}
