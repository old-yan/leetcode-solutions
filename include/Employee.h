#include <iostream>
#include <vector>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
    Employee(int _id,int _importance,vector<int>&&_subordinates):id(_id),importance(_importance),subordinates(_subordinates){}
};