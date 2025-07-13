class Solution {
public:
    // Helper recursive function
    bool checkPalindrome(int i, const string& s) {
        if (i >= s.size() / 2) return true;
        if (s[i] != s[s.size() - i - 1]) return false;
        return checkPalindrome(i + 1, s);
    }

    bool isPalindrome(string s) {
        string cleaned = "";
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }
        return checkPalindrome(0, cleaned);
    }
};