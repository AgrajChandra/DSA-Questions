class Router {
public:
    using int3=array<int,3>; //(timestamp, source, destination)
    deque<int3> q;           
    unordered_map<int, deque<int>> byDest; // destination -> timestamps
    unordered_set<long long> seen;          // pack(source,dest)
    size_t memoryLimit;

    Router(size_t memoryLimit): memoryLimit(memoryLimit) {}

    // pack source & destination into long long
    long long pack(int x, int y) { return ((long long)x<<32)|y; }

    bool addPacket(int source, int destination, int timestamp) {
        if (!q.empty() && timestamp==q.back()[0]) {
            long long key=pack(source, destination);
            if (seen.count(key)) return 0; // duplicate 
        } 
        else 
            seen.clear(); // new timestamp batch, reset seen

        // If memory limit reached, remove oldest packet
        if (q.size()==memoryLimit) {
            auto old=q.front(); 
            q.pop_front();

            auto& qq=byDest[old[2]];
            if (!qq.empty()) qq.pop_front();

            if (old[0]==timestamp)//same timestamp with oldest packet
                seen.erase(pack(old[1], old[2]));
        }

        // Add new packet
        q.push_back({timestamp, source, destination});
        byDest[destination].push_back(timestamp);
        seen.insert(pack(source, destination));
        return 1;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto x=q.front(); 
        q.pop_front();

        auto& qq=byDest[x[2]];
        if (!qq.empty()) qq.pop_front();

        if (q.back()[0]==x[0])// front & back have the same timestamp
            seen.erase(pack(x[1], x[2]));

        return {x[1], x[2], x[0]};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& qq=byDest[destination];
        // timestamps are sorted, use binary search
        auto itL=lower_bound(qq.begin(), qq.end(), startTime);
        auto itR=upper_bound(qq.begin(), qq.end(), endTime);
        return itR-itL;
    }
};
