class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : word) {
            freq[ch - 'a']++;
        }

        // Sort the frequencies
        sort(freq.begin(), freq.end());

        int n = word.size();
        int ans = INT_MAX;

        // Skip zeros (characters not in the word)
        int t = 0;
        while (t < 26 && freq[t] == 0) t++;

        // Try each freq[i] as baseline x
        for (int i = t; i < 26; ++i) {
            int x = freq[i];
            int deletions = 0;

            for (int j = t; j < 26; ++j) {
                int y = freq[j];
                if (y < x) {
                    deletions += y; // delete all of these
                } else if (y > x + k) {
                    deletions += y - (x + k); // delete excess
                }
            }
            ans = min(ans, deletions);
        }

        return ans;
    }
};
