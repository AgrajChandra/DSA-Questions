class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        uint8_t freq[101] = {0};
        uint8_t max = 0;
        int res = 0;
        for (int n : nums) {
            uint8_t f = ++freq[n];
            if (f > max) {
                max = f;
                res = f;
            } else if (f == max) {
                res += f;
            }
        }
        return res;
    }
};