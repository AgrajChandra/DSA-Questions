class Solution {
public:
    int reverse(int x) {
        int rev_number = 0;
        while (x != 0) {
            int last_digit = x % 10;
            if( rev_number > INT_MAX/10 || rev_number < INT_MIN/10){
                return 0;
            }
           
            rev_number = (rev_number * 10) + last_digit;
            x = x / 10;
        }
        return rev_number;
    }
};
