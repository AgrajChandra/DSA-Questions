using namespace std;

class Solution {
    static inline int req;
    static inline long long ans;
    static inline int numArr[1000000];
    static inline int sizeArr[1000000];

public:
    static long long kMirror(int k, int n) {

        req = n;
        ans = 0;
        numArr[0] = 1;
        sizeArr[0] = 1;
        int idx = 1;

        while (req > 0) {
            int num = numArr[--idx];
            int size = sizeArr[idx];

            int arr[20];
            int tmp = num, len = 0;
            while (tmp) {
                len++;
                tmp /= 10;
            }
            tmp = num;
            int i = len - 1, mid = i, j = size - 1;
            bool allNine = true;

            for (; i >= 0; --i) {
                int d = tmp % 10;
                arr[i] = d;
                if (d != 9) allNine = false;
                tmp /= 10;
            }
            for (i = 0; j > mid; ) {
                arr[j--] = arr[i++];
            }

            long long number = 0;
            for (int p = 0; p < size; ++p) {
                number = number * 10 + arr[p];
            }

            if (isBaseKPal(number, k)) {
                ans += number;
                if (--req == 0) break;
            }

            if (allNine) {
                int nextSize = size + 1;
                int nextNum = (size & 1) ? ((num + 1) / 10) : (num + 1);
                numArr[idx] = nextNum;
                sizeArr[idx] = nextSize;
            } else {
                numArr[idx] = num + 1;
                sizeArr[idx] = size;
            }
            ++idx;
        }

        return ans;
    }

private:
    static inline bool isBaseKPal(long long x, int k) {
        long long buf[64];
        int t = 0;
        while (x) {
            buf[t++] = x % k;
            x /= k;
        }
        for (int a = 0, b = t - 1; a < b; ++a, --b) {
            if (buf[a] != buf[b]) return false;
        }
        return true;
    }
};