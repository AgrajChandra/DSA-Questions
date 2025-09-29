class Solution {
  public:
    int search(vector<int>& arr, int x) {
        // code here
        int index = 0;
        for(auto no : arr ){
            if(no == x)
                return index;
            index ++;
        }
        return -1;
    }
};