class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for (int i = 0; i < s.length(); i += k) {
            if (i + k > s.length()) 
                ans.push_back(s.substr(i) + string(i + k - s.length(), fill));
            else
                ans.push_back(s.substr(i, k));
        }
        return ans;
    }
};