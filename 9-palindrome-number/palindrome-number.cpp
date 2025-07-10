class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int rev_half = 0;
        while (x > rev_half) {
            int last_digit = x % 10;
            rev_half = rev_half * 10 + last_digit;
            x = x / 10;
        }

        // For even digits: x == rev_half
        // For odd digits:  x == rev_half / 10
        return x == rev_half || x == rev_half / 10;
    }
};
