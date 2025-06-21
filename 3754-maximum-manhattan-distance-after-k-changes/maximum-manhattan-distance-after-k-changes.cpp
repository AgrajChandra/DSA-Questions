class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        vector<pair<char,char>> dirs = {{'N','E'}, {'N','W'}, {'S','E'}, {'S','W'}};

        for (auto [d1, d2] : dirs) {
            int curr = 0, rem = k;
            for (char c : s) {
                if (c == d1 || c == d2) {
                    curr++;  // aligned direction
                } else {
                    if (rem > 0) {
                        rem--;
                        curr++;  // use change to flip a bad move
                    } else {
                        curr--;  // unaligned and no changes left
                    }
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};
