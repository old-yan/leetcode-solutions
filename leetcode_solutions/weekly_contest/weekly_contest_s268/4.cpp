#include "utils.h"

long long table[10][31]={0};

//将一个前缀拼成奇数长度的回文数，例如：31415->314151413
long long make_odd(long long prefix){
    static long long stack[10];
    int len=0;
    while(prefix)
        stack[len++]=prefix%10,prefix/=10;
    long long res=0;
    //这里循环结束时 i==0 ，所以在上述例子里 5 只会参与一次计算，
    for(int i=len-1;i>0;i--)
        res=res*10+stack[i];
    for(int i=0;i<len;i++)
        res=res*10+stack[i];
    return res;
}
//将一个前缀拼成偶数长度的回文数，例如：31415->3141551413
long long make_even(long long prefix){
    static long long stack[10];
    int len=0;
    while(prefix)
        stack[len++]=prefix%10,prefix/=10;
    long long res=0;
    //这里循环结束时 i<0 ，所以在上述例子里 5 会参与两次计算，
    for(int i=len-1;i>=0;i--)
        res=res*10+stack[i];
    for(int i=0;i<len;i++)
        res=res*10+stack[i];
    return res;
}
//检查一个数在 k 进制下是否回文
bool check(long long n,int k){
    static int stack[100];
    int len=0;
    while(n)
        stack[len++]=n%k,n/=k;
    for(int i=0,j=len-1;i<j;i++,j--)
        if(stack[i]!=stack[j])return false;
    return true;
}

auto init_work=[]{
    for(int k=2;k<=9;k++){
        int cnt=0;
        // prefix1 用来枚举奇数长度数字
        // prefix2 用来枚举偶数长度数字
        long long prefix1=1,prefix2=1;
        //循环直到凑够 30 个数
        while(cnt<30){
            long long odd=make_odd(prefix1);
            long long even=make_even(prefix2);
            if(odd<even){
                if(check(odd,k))table[k][++cnt]=odd;
                prefix1++;
            }
            else{
                if(check(even,k))table[k][++cnt]=even;
                prefix2++;
            }
        }
        //求出前缀和
        partial_sum(table[k],table[k+1],table[k]);
    }
    return 0;
}();

class Solution {
public:
    //本题正解就是打表（雾
    //当然打表也有技巧，个人电脑上跑个时间复杂度几百亿的程序，跑得也很心焦
    long long kMirror(int k, int n) {
        return table[k][n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int k=3;
    int n=7;
    auto ans=sol.kMirror(k,n);
    DBG(ans);

    system("pause");
    return 0;
}