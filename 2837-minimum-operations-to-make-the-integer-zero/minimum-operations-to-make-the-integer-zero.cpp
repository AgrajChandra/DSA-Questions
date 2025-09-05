class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num2 >= num1)
        return -1;

        int k = 1;

        while(true)
        {
            long long int temp = (1LL * num1) - (1LL * k * num2);
            if(temp <= 0)
            return -1;

            int count = __builtin_popcountll(temp); 
            if(k >= count && k <= temp)
            return k;   

            k++;
        }

        return -1;
    }
};