#include "utils.h"

template<class T>
class LazyTree{
    typedef function<T(T&,T&)> Operation;
    struct elem{
        T val;
        T inc;
        bool b;
        elem():val(),inc(),b(false){}
        elem(T _val):val(_val),inc(),b(false){}
        elem(T _val,T _inc):val(_val),inc(_inc),b(false){}
        elem(T _val,T _inc,bool _b):val(_val),inc(_inc),b(_b){}
    };
    inline int size(int i){
        return __builtin_clz(i)+Y-31;
    }
    void inherite(int i,T inc){
        data[i].val=data[i].inc=inc;
        data[i].b=true;
    }
public:
    elem*data;
    int X,Y;
    T default_val;
    Operation op;
    bool addition;
    LazyTree(int n,T _default_val,Operation _op,bool _addition=false):default_val(_default_val),op(_op),addition(_addition){
        for(X=4;X<n;X<<=1);
        Y=__builtin_ctz(X);
        data=new elem[X*2];
        fill(data+X,data+X*2,elem(default_val));
        for(int i=X-1;i;i--){
            data[i].val=op(data[i*2].val,data[i*2+1].val);
        }
    }
    template<class Tlike>
    LazyTree(vector<Tlike>&nums,T _default_val,Operation _op,bool _addition=false):default_val(_default_val),op(_op),addition(_addition){
        for(X=4;X<nums.size();X<<=1);
        Y=__builtin_ctz(X);
        data=new elem[X*2];
        for(int i=0;i<X;i++){
            data[X+i]=elem(i<nums.size()?nums[i]:default_val);
        }
        for(int i=X-1;i;i--){
            data[i]=elem(op(data[i*2].val,data[i*2+1].val));
        }
    }
    void set(int i,T inc){
        push_down(i);
        data[i+=X].val=inc;
        while(i>>=1){
            data[i].val=op(data[i*2].val,data[i*2+1].val);
        }
    }
    void step(int i,T inc){
        push_down(i);
        inherite(i+=X,inc);
        while(i>>=1){
            data[i].val=op(data[i*2].val,data[i*2+1].val);
        }
    }
    void step(int l,int r,T inc){
        if(l==r)step(l,inc);
        else{
            push_down(l);
            push_down(r);
            inherite(l+=X,inc);
            inherite(r+=X,inc);
            while((l>>1)!=(r>>1)){
                if(l%2==0)inherite(l+1,inc);
                if(r%2)inherite(r-1,inc);
                data[l>>1].val=op(data[l].val,data[l^1].val);
                data[r>>1].val=op(data[r].val,data[r^1].val);
                l>>=1;
                r>>=1;
                if(addition)inc<<=1;
            }
            while(l>>=1){
                data[l].val=op(data[l*2].val,data[l*2+1].val);
            }
        }
    }
    void push_down(int i){
        for(int j=Y,k=1;j;k=(i&(1<<--j))?(k<<1)+1:k<<1){
            if(data[k].b){
                inherite(k*2,addition?data[k].inc/2:data[k].inc);
                inherite(k*2+1,addition?data[k].inc/2:data[k].inc);
                data[k]=elem(data[k].val);
            }
        }
    }
    T& operator[](int i){
        push_down(i);
        return data[i+X].val;
    }
    T operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return default_val;
        if(l==r)return (*this)[l];
        push_down(l);
        push_down(r);
        T res=op(data[l+=X].val,data[r+=X].val);
        while(l/2!=r/2){
            if(l%2==0)res=op(res,data[l+1].val);
            if(r%2)res=op(res,data[r-1].val);
            l>>=1;
            r>>=1;
        }
        return res;
    }
    int find_nth(T n){
        if(n<data[1]){
            int i=1;
            while(i<X){
                if(data[i].b){
                    data[i*2].inherite(data[i].inc/2);
                    data[i*2+1].inherite(data[i].inc/2);
                    data[i]=elem(data[i].val);
                }
                if(data[i*2].val>=n+1){
                    i<<=1;
                }
                else{
                    n-=data[i*2].val;
                    i=(i<<1)+1;
                }
            }
            return i-X;
        }
        else return -1;
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vi old;
        for(auto&position:positions){
            old.pb(position[0]);
            old.pb(position[0]+position[1]-1);
        }
        vi rnk=getrank2(old);
        unordered_map<int,int>M;
        REP(i,old.size())M[old[i]]=rnk[i];
        LazyTree<int> T(M.size(),0,[](int x,int y){return max(x,y);});
        vi ans;
        for(auto&position:positions){
            int left=M[position[0]],right=M[position[0]+position[1]-1];
            int height=T(left,right)+position[1];
            T.step(left,right,height);
            ans.pb(T.data[1].val);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi positions=makevvi("[[4, 9], [8, 8], [6, 8], [8, 2]]");
    auto ans=sol.fallingSquares(positions);
    DBGV(ans);

    system("pause");
    return 0;
}
