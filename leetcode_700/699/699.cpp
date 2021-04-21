#include "utils.h"

template<class T>
struct LazyTree{
    #define LAZYTREEDEPTH 8
    typedef function<T(T&,T&)> Operation;
    inline int size(int i){
        return __builtin_clz(i)+Y-31;
    }
    //重载inherite，描述继承增量时的结点形为
    void inherite(int i,T _inc){
        data[i]=_inc;
        inc[i]=_inc;
        lazy[i]=true;
    }
    T data[1<<(LAZYTREEDEPTH+1)]={0},inc[1<<(LAZYTREEDEPTH+1)]={0},default_val{0},default_inc{0};
    bool lazy[1<<(LAZYTREEDEPTH+1)]={0};
    int X,Y;
    Operation op;
    LazyTree(int n,Operation _op):op(_op){
        cout<<"attention TREESIZE,<="<<(1<<LAZYTREEDEPTH)<<'\n';
        for(X=4,Y=2;X<n;X<<=1,Y++);
    }
    template<class Tlike>
    void set(const vector<Tlike>&nums,T val=0){
        for(int i=0;i<nums.size();i++){
            data[X+i]=nums[i];
        }
        fill(data+X+nums.size(),data+X*2,val);
        for(int i=X-1;i;i--){
            data[i]=op(data[i*2],data[i*2+1]);
        }
    }
    void set(T val){
        fill(data+X,data+X*2,val);
        for(int i=X-1;i;i--){
            data[i]=op(data[i*2],data[i*2+1]);
        }
        fill(inc,inc+X*2,default_inc);
        fill(lazy,lazy+X*2,false);
    }
    void setinc(T _inc){
        default_inc=_inc;
        fill(inc,inc+X*2,_inc);
    }
    void set(int i,T val){
        push_down(i);
        data[i+=X]=val;
        while(i>>=1){
            data[i]=op(data[i*2],data[i*2+1]);
        }
    }
    void step(int i,T _inc){
        push_down(i);
        inherite(i+=X,_inc);
        while(i>>=1){
            data[i]=op(data[i*2],data[i*2+1]);
        }
    }
    void step(int l,int r,T _inc){
        if(l==r)step(l,_inc);
        else if(l<r){
            push_down(l);
            push_down(r);
            inherite(l+=X,_inc);
            inherite(r+=X,_inc);
            while((l>>1)!=(r>>1)){
                if(l%2==0)inherite(l+1,_inc);
                if(r%2)inherite(r-1,_inc);
                data[l>>1]=op(data[l],data[l^1]);
                data[r>>1]=op(data[r],data[r^1]);
                l>>=1;
                r>>=1;
            }
            while(l>>=1){
                data[l]=op(data[l*2],data[l*2+1]);
            }
        }
    }
    void push_down(int i){
        for(int j=Y,k=1;j;k=(i&(1<<--j))?(k<<1)+1:k<<1){
            if(lazy[k]){
                inherite(k*2,inc[k]);
                inherite(k*2+1,inc[k]);
                inc[k]=default_inc;
                lazy[k]=false;
            }
        }
    }
    T& operator[](int i){
        push_down(i);
        return data[i+X];
    }
    T operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return default_val;
        if(l==r)return (*this)[l];
        push_down(l);
        push_down(r);
        T res=op(data[l+=X],data[r+=X]);
        while(l/2!=r/2){
            if(l%2==0)res=op(res,data[l+1]);
            if(r%2)res=op(res,data[r-1]);
            l>>=1;
            r>>=1;
        }
        return res;
    }
    int find_nth(T n){
        if(n<data[1]){
            int i=1;
            while(i<X){
                if(lazy[i]){
                    inherite(i*2,inc[i]);
                    inherite(i*2+1,inc[i]);
                    inc[i]=default_inc;
                    lazy[i]=false;
                }
                if(data[i*2]>=n+1){
                    i<<=1;
                }
                else{
                    n-=data[i*2];
                    i=(i<<1)+1;
                }
            }
            return i-X;
        }
        else return -1;
    }
};

LazyTree<int> T(2000,[](int x,int y){return max(x,y);});
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vi old;
        int n=positions.size();
        for(auto&position:positions){
            old.pb(position[0]);
            old.pb(position[0]+position[1]-1);
        }
        vi rnk=getrank2(old);
        vi ans;
        T.set(0);
        REP(i,n){
            int left=rnk[i*2],right=rnk[i*2+1];
            int height=T(left,right)+positions[i][1];
            T.step(left,right,height);
            ans.pb(T.data[1]);
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
