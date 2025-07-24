static const int N=1000;
vector<int> adj[N];
struct Node{
    int in=0, out=0, xorSum=0;
    Node(){}
};
Node v[N];

class Solution {
public:
    int timer;

    void dfs(int i, int p, vector<int>& nums) {
        auto& node=v[i];
        node.in=timer++;
        node.xorSum=nums[i];
        for (int j: adj[i]) {
            if (j==p) continue;
            dfs(j, i, nums);
            node.xorSum^=v[j].xorSum;
        }
        node.out=timer++;
    }

    bool isAncestor(int anc, int desc) {
        return v[anc].in<=v[desc].in && v[desc].out<=v[anc].out;
    }
    int score(int x, int y, int z){
        //bubble sort
        if(x>y) swap(x,y);
        if(y>z) swap(y,z);
        if(x>y) swap(x,y);
        return z-x;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        const int n=nums.size();
        
        for (int i=0; i<n; i++){
            adj[i].clear();
            v[i]=Node();
        }

        for (auto& e : edges) {
            const int i=e[0], j=e[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        timer=0;
        dfs(0, -1, nums);
        int total=v[0].xorSum;
        int ans=INT_MAX;

        // Try all pairs of cuts
        for (int i=1; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int x, y, z;
                const int xI=v[i].xorSum, xJ=v[j].xorSum;
                if (isAncestor(i, j)) {
                    x=xJ;
                    y=xI^xJ;
                    z=total^xI;
                } 
                else if (isAncestor(j, i)) {
                    x=xI;
                    y=xI^xJ;
                    z=total^xJ;
                } 
                else {
                    x=xI;
                    y=xJ;
                    z=total^x^y;
                }
                ans=min(ans, score(x, y, z));
            }
        }
        return ans;
    }
};