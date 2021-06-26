#include "utils.h"

class Solution {
    //getc函数，传入一个起始下标
    //遍历这段合法区间后，返回这段区间为0，为1的最小代价
    pair<int,int> getc(int&idx,string&expression){
        //需要维护四个变量
        //one当前值为1所需的最小代价
        //zero当前值为0所需的最小代价
        //andc当前运算符为and所需的最小代价
        //orc当前运算符为or所需的最小代价

        //初始时，默认当前值为1，当前运算符为and
        int one=0,zero=0x3f3f3f3f,andc=0,orc=0x3f3f3f3f;
        while(expression[idx]){
            int val,next_zero,next_one;
            if(expression[idx]=='1'){
                next_zero=1,next_one=0;
            }
            else if(expression[idx]=='0'){
                next_zero=0,next_one=1;
            }
            else if(expression[idx]=='('){
                idx++;
                auto [a,b]=getc(idx,expression);
                next_zero=a,next_one=b;
            }
            int tmp=one;
            //按照之前one,two,andc,orc的代价，结合next_zero,next_one的代价，获取接下来zero和one的最小代价
            one=min({one+orc+min(next_zero,next_one),min(zero,one)+orc+next_one,one+andc+next_one});
            zero=min({tmp+andc+next_zero,zero+andc+next_zero,zero+andc+next_one,zero+orc+next_zero});
            if(!expression[++idx]||expression[idx]==')')break;
            if(expression[idx]=='|')orc=0,andc=1;
            else orc=1,andc=0;
            idx++;
        }
        return {zero,one};
    }
public:
    int minOperationsToFlip(string expression) {
        int idx=0;
        auto[zero,one]=getc(idx,expression);
        return zero+one;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string expression="1&(0|1)";
    auto ans=sol.minOperationsToFlip(expression);
    DBG(ans);

    system("pause");
    return 0;
}
