class Solution {
public:
    long long expSum4[18]={1};
    long long expSum(unsigned x){
        if (x==0) return 0;
        int log4=(31-countl_zero(x))/2;
        int r=x-(1<<(2*log4));
        return expSum4[log4]+r*(log4+1LL);
    }
    long long minOperations(vector<vector<int>>& queries) {
        for(int i=1; i<18; i++){
            expSum4[i]=expSum4[i-1]+3LL*i*(1LL<<(2*(i-1)))+1;
        //    cout<<i<<"->"<<expSum4[i]<<", ";
        }
        long long op=0;
        for(auto& q: queries){
            int l=q[0]-1, r=q[1];
            op+=(expSum(r)-expSum(l)+1)/2;// ceiling of (expSum(r)-expSum(l))/2
        }
        return op;
    }
};