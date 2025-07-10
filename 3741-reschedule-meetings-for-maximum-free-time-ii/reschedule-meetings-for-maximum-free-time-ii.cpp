class Solution {
public:
    int maxFreeTime(int eventTime, const vector<int>& startTime, const vector<int>& endTime) {
    int len = startTime.size();
    vector<int> gaps(len + 1);
    int lastEnd = 0;

    for (int i = 0; i < len; ++i) {
        gaps[i] = startTime[i] - lastEnd;
        lastEnd = endTime[i];
    }

    gaps[len] = eventTime - lastEnd;

    vector<int> rightMax(len + 1, 0);
    for (int i = len - 1; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], gaps[i + 1]);
    }

    int leftMax = 0;
    int maxGap = 0;

    for (int i = 1; i <= len; ++i) {
        int dur = endTime[i - 1] - startTime[i - 1];
        int gapL = gaps[i - 1];
        int gapR = gaps[i];

        if (leftMax >= dur || rightMax[i] >= dur)
            maxGap = max(maxGap, gapL + dur + gapR);

        maxGap = max(maxGap, gapL + gapR);
        leftMax = max(leftMax, gapL);
    }

    return maxGap;
}

};