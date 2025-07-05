class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        int lucky = -1;

        for (auto& [key, value] : freq) {
            if (key == value) {
                lucky = max(lucky, key);
            }
        }

        return lucky;
    }
};