class Solution {
public:
    int longestSubsequence(string s, int k) {
        int oneCount = 0;
        long long num = 0;
        long long pw = 1;

        // Greedily take '1's from right to left (least significant bits) if they fit.
        for (int i = s.size() - 1; i >= 0 && num + pw <= k; --i) {
            if (s[i] == '1') {
                ++oneCount;
                num += pw;
            }
            pw <<= 1;  // move to next bit weight
        }

        // All zeros can always be included
        int zeroCount = 0;
        for (char c : s) if (c == '0') ++zeroCount;

        return zeroCount + oneCount;
    }
};
