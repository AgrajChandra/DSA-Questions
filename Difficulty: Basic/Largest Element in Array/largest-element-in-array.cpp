class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int max = arr[0];
        for (auto no : arr){
            if (no > max)
                max = no;
        }
        return max;
    }
};
