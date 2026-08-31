class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({deadline[i], profit[i]});
        }

        sort(arr.begin(), arr.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < n; i++) {
            minHeap.push(arr[i].second);

            if (minHeap.size() > arr[i].first) {
                minHeap.pop(); 
            }
        }

        int count = minHeap.size();
        int totalProfit = 0;

        while (!minHeap.empty()) {
            totalProfit += minHeap.top();
            minHeap.pop();
        }

        return {count, totalProfit};
    }
};