class Solution {
public:
    int maximum69Number (int num) {
        int a=-1;
        for(int n=num, d=0; n>0; n/=10, d++) {
            int r=n%10;
            if (r==6) a=d;
        }
        return (a==-1)?num:int(num+3*pow(10,a));     
    }
};