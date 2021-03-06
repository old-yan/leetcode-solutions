#include "utils.h"

class Solution {
    int N,first_type=-1,second_type=-1;
    int type[30];
    bitset<30>b[30];
public:
    int movesToChessboard(vector<vector<int>>& board) {
        N=board.size();
        if(N%2){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++)if(board[i][j])b[i].set(j);
                if(b[i].count()==N/2+1){
                    if(first_type<0)first_type=i;
                    else if(b[i]!=b[first_type])return -1;
                    type[i]=1;
                }
                else{
                    if(second_type<0)second_type=i;
                    else if(b[i]!=b[second_type])return -1;
                    type[i]=2;
                }
            }
            if((b[first_type]&b[second_type]).count())return -1;
            int first_count=accumulate(type,type+N,0,[](int cnt,int val){return cnt+(val==1);});
            if(first_count!=N/2&&first_count!=N/2+1)return -1;
            int most_type=first_count==N/2?2:1;
            int ans1=0,ans2=0;
            for(int i=0;i<N;i+=2)if(type[i]!=most_type)ans1++;
            for(int j=0;j<N;j+=2)if(!b[first_type][j])ans2++;
            return ans1+ans2;
        }
        else{
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++)if(board[i][j])b[i].set(j);
                if(b[i].count()!=N/2)return -1;
                if(first_type<0||b[i]==b[first_type]){
                    if(first_type<0)first_type=i;
                    type[i]=1;
                }
                else{
                    if(second_type<0)second_type=i;
                    else if(b[i]!=b[second_type])return -1;
                    type[i]=2;
                }
            }
            if(second_type<0)return -1;
            if((b[first_type]&b[second_type]).count())return -1;
            int first_count=accumulate(type,type+N,0,[](int cnt,int val){return cnt+(val==1);});
            if(first_count!=N/2)return -1;
            int ans1=0,ans2=0;
            for(int i=0;i<N;i+=2)if(type[i]==2)ans1++;
            for(int j=0;j<N;j+=2)if(!b[first_type][j])ans2++;
            return min(ans1,N/2-ans1)+min(ans2,N/2-ans2);
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi board=makevvi("[[1,1,0],[0,0,1],[0,0,1]]");
    auto ans=sol.movesToChessboard(board);
    DBG(ans);

    system("pause");
    return 0;
}
