int st[150], top=-1;//mono stack
int cnt[150]={0};
class Solution {
public:
    static int numSubmat(vector<vector<int>>& mat) {
        const int r=mat.size(), c=mat[0].size();
 
        int ans=0;
        for (int i=0; i<r; i++){
            auto& h=mat[i];//height
            top=-1;// reset mono stack
            fill(cnt, cnt+c, 0);
            for(int j=0; j<c; j++){
                if (i>0 && h[j]>0) 
                    h[j]+=mat[i-1][j];// height for mat[i][j]
                
                while(top>-1 && h[st[top]]> h[j]) 
                    top--;// pop
                int left=(top==-1)?-1:st[top];
                cnt[j]=(top>-1?cnt[left]:0)+h[j]*(j-left);
                ans+=cnt[j];
                st[++top]=j;// push j to stack
            }
        }
        return ans;
    }
};