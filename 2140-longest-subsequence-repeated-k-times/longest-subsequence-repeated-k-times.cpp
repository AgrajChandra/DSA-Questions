class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        // valid chars that can appear k times
        vector<char> valid;
        for (int i = 0; i < 26; i++)
            if (cnt[i] >= k)
                valid.push_back('a' + i);

        queue<string> q;
        q.push("");
        string ans = "";

        auto ok = [&](const string &t) {
            int need = k, idx = 0;
            for (char c : s) {
                if (c == t[idx]) {
                    idx++;
                    if (idx == t.size()) {
                        need--;
                        if (need == 0) return true;
                        idx = 0;
                    }
                }
            }
            return false;
        };

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            // pruning: if even the longest could not fit within s, stop
            if ((long long)cur.size() * k > s.size()) break;

            for (char c : valid) {
                string nxt = cur + c;
                if (ok(nxt)) {
                    q.push(nxt);
                    ans = nxt;  // BFS ensures longer, lexicographically larger
                }
            }
        }
        return ans;
    }
};
