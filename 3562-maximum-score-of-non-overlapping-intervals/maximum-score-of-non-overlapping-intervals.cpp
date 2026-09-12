class Solution {
private:
    struct DPState {
        long long weight = 0;
        vector<int> indices;

        bool isBetterThan(const DPState& other) const {
            if (weight != other.weight) {
                return weight > other.weight;
            }
            return indices < other.indices;
        }
    };

    struct Interval {
        int start;
        int end;
        int weight;
        int id;

        bool operator<(const Interval& other) const {
            if (start != other.start)
                return start < other.start;
            if (end != other.end)
                return end < other.end;
            return id < other.id;
        }
    };

    int n;
    vector<Interval> intervals;
    vector<vector<DPState>> memo;
    vector<vector<bool>> visited;

    DPState solve(int idx, int k) {
        if (k == 0 || idx >= n) {
            return {0, {}};
        }

        if (visited[idx][k]) {
            return memo[idx][k];
        }

        // Option 1: Skip current interval
        DPState bestState = solve(idx + 1, k);

        // Option 2: Take current interval
        int low = idx + 1;
        int high = n;
        int nextIdx = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (intervals[mid].start > intervals[idx].end) {
                nextIdx = mid;
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        DPState takeState = solve(nextIdx, k - 1);

        takeState.weight += intervals[idx].weight;
        takeState.indices.push_back(intervals[idx].id);

        sort(takeState.indices.begin(), takeState.indices.end());

        if (takeState.isBetterThan(bestState)) {
            bestState = takeState;
        }

        visited[idx][k] = true;
        return memo[idx][k] = bestState;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& inputIntervals) {
        n = inputIntervals.size();

        intervals.resize(n);

        for (int i = 0; i < n; i++) {
            intervals[i] = {
                inputIntervals[i][0],
                inputIntervals[i][1],
                inputIntervals[i][2],
                i
            };
        }

        sort(intervals.begin(), intervals.end());

        // At most 4 intervals can be selected
        memo.assign(n, vector<DPState>(5));
        visited.assign(n, vector<bool>(5, false));

        DPState result = solve(0, 4);

        return result.indices;
    }
};