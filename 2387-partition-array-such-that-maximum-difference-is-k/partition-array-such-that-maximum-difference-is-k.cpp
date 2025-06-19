class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>result;
        int q = result.size();

        int key = nums[0];
        int window = 1;
        for(int i=0; i<n; i++){
            if(nums[i] - key > k){
                key = nums[i];
                window++;
    
            }
        }
        return window;
        


    }
};