#pragma once
#include <vector>
#include <iomanip>
using namespace std;
#define OLDYAN_NESTEDINTEGER

class NestedInteger {
    vector<NestedInteger>data;
    int val;
    bool signal;
public:
    NestedInteger():signal(false){}
    NestedInteger(int num):val(num),signal(true){}
    NestedInteger(vector<NestedInteger>_data):data(_data),signal(false){}
    bool isInteger() const{return signal;}
    int getInteger() const{return val;}
    void setInteger(int value){signal=true;val=value;}
    void add(const NestedInteger&ni){signal=false;data.emplace_back(ni);};
    const vector<NestedInteger> &getList() const{return data;}
};

ostream&operator<<(ostream&out,const NestedInteger&obj){
    if(obj.isInteger()){
        out<<obj.getInteger();
    }
    else{
        out<<'[';
        for(int i=0;i<obj.getList().size();i++){
            if(i)out<<',';
            out<<obj.getList()[i];
        }
        out<<"]";
    }
    return out;
}