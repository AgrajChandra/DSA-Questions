class Solution 
{
public:
    pair<int, int> dfs(int n, int p1, int p2) 
    {
        // Step 1: Base case — they meet
        if (p1 + p2 == n + 1) 
        {
            return {1, 1};
        }

        // Step 2: Normalize
        if (p1 > p2) 
        {
            swap(p1, p2);
        }
        
        if (n <= 4) 
        {
            return {2, 2};
        }

        int m = (n + 1) / 2;
        int minR = INT_MAX;
        int maxR = INT_MIN;

        // Step 3: Use symmetry to reduce state space
        if (p1 - 1 > n - p2) 
        {
            int t = n + 1 - p1;
            p1 = n + 1 - p2;
            p2 = t;
        }

        // Step 4: Simulate all scenarios
        if (p2 * 2 <= n + 1) 
        {
            int a = p1 - 1;
            int b = p2 - p1 - 1;

            for (int i = 0; i <= a; ++i) 
            {
                for (int j = 0; j <= b; ++j) 
                {
                    auto [r1, r2] = dfs(m, i + 1, i + j + 2);
                    minR = min(minR, r1 + 1);
                    maxR = max(maxR, r2 + 1);
                }
            }
        } 
        else 
        {
            int p4 = n + 1 - p2;
            int a = p1 - 1;
            int b = p4 - p1 - 1;
            int c = p2 - p4 - 1;

            for (int i = 0; i <= a; ++i) 
            {
                for (int j = 0; j <= b; ++j) 
                {
                    int offset = i + j + 1 + (c + 1) / 2 + 1;
                    auto [r1, r2] = dfs(m, i + 1, offset);
                    minR = min(minR, r1 + 1);
                    maxR = max(maxR, r2 + 1);
                }
            }
        }

        // Step 5: Return earliest and latest round
        return {minR, maxR};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) 
    {
        auto [earliest, latest] = dfs(n, firstPlayer, secondPlayer);
        return {earliest, latest};
    }
};