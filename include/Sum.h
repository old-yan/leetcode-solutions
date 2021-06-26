#include <vector>
#include <memory.h>
using namespace std;

template<class T=int>
struct Sumer{
    #define SUMERLEN 100000
    T A[SUMERLEN+1]={0};
    int len;
    template<class iterator>
    void build(iterator begin, iterator end){
        len=end-begin;
        for(int i=0;i<len;i++)
            A[i+1]=A[i]+*(begin+i);
    }
    T query(int left, int right){
        if(left>(right=min(right,len-1)))return 0;
        return A[right+1]-A[left];
    }
};


template<class T=int,uint8_t mask=31>
struct Sumer2d{
    #define SUMER2dLEN 1000
    T A[5][SUMER2dLEN+1][SUMER2dLEN+2]={0},m=0,n=0;
    void build(const vector<vector<int>>&mat){
        for(int k=0;k<5;k++)if(mask>>k&1)
            for(int i=1;i<=m;i++)
                memset(A[k][i]+1,0,n*sizeof(T));
        m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++)
            for(int j=0,k=0;j<n;j++){
                k+=mat[i][j];
                if constexpr(mask&1)A[0][i+1][j+1]=k;
                if constexpr(mask>>1&1)A[1][i+1][j+1]=A[1][i][j+1]+mat[i][j];
                if constexpr(mask>>2&1)A[2][i+1][j+1]=A[2][i][j]+mat[i][j];
                if constexpr(mask>>3&1)A[3][i+1][j+1]=A[3][i][j+2]+mat[i][j];
                if constexpr(mask>>4&1)A[4][i+1][j+1]=A[4][i][j+1]+k;
            }
    }
    T query_row(int r,int c1,int c2){
        return A[0][r+1][c2+1]-A[0][r+1][c1];
    }
    T query_col(int c,int r1,int r2){
        return A[1][r2+1][c+1]-A[1][r1][c+1];
    }
    T query_dif(int r1,int c1,int r2,int c2){
        return A[2][r2+1][c2+1]-A[2][r1][c1];
    }
    T query_sum(int r1,int c1,int r2,int c2){
        return A[3][r2+1][c2+1]-A[3][r1][c1+2];
    }
    T query_area(int r1,int c1,int r2,int c2){
        return A[4][r2+1][c2+1]+A[4][r1][c1]-A[4][r2+1][c1]-A[4][r1][c2+1];
    }
};