class Solution {
public:
    static int maximumLength(vector<int>& nums) {
        const int n=nums.size(); 
        if (n==2) return 2;
        bool z=nums[0]&1;
        int len[3]={!z, z, 1};
        for (int i=1; i<n; i++){
            bool x=nums[i]&1;
            len[x&1]++;
            if (x!=z){
                len[2]++;
                z=!z;
            }
        }
        return max({len[0], len[1], len[2]});
    }
};