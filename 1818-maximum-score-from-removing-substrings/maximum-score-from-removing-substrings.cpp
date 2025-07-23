#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalPoints = 0;
        string high_priority_pair = (x > y) ? "ab" : "ba";
        string low_priority_pair = (x > y) ? "ba" : "ab";
        int high_priority_score = max(x, y);
        int low_priority_score = min(x, y);

        // First pass: remove high priority pairs
        pair<int, string> after_first_pass = solve(s, high_priority_pair, high_priority_score);
        totalPoints += after_first_pass.first;

        // Second pass: remove low priority pairs from the remaining string
        pair<int, string> after_second_pass = solve(after_first_pass.second, low_priority_pair, low_priority_score);
        totalPoints += after_second_pass.first;
        
        return totalPoints;
    }

private:
    // Helper function to process the string and remove a specific pattern
    pair<int, string> solve(const string& text, const string& pattern, int score) {
        string stack;
        int points = 0;
        for (char c : text) {
            if (!stack.empty() && stack.back() == pattern[0] && c == pattern[1]) {
                stack.pop_back();
                points += score;
            } else {
                stack.push_back(c);
            }
        }
        return {points, stack};
    }
};