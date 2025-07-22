class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        map<int, int> mp;
        int sum = 0, maxi = 0;

        while (r < n) {
            mp[nums[r]]++;
            sum += nums[r];

            while (r - l + 1 > mp.size()) {
                mp[nums[l]]--;
                sum -= nums[l];
                if (mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }

            maxi = max(maxi, sum);
            r++;
        }

        return maxi;
    }
};