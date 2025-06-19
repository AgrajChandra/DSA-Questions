class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        vector<int> minCoinsDP(amount + 1, INT_MAX);
        minCoinsDP[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && minCoinsDP[i - coin] != INT_MAX) {
                    minCoinsDP[i] = min(minCoinsDP[i], 1 + minCoinsDP[i - coin]);
                }
            }
        }
        return (minCoinsDP[amount] == INT_MAX) ? -1 : minCoinsDP[amount];
    }
};
