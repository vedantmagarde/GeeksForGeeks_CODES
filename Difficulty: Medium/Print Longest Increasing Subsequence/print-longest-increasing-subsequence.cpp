class Solution {
public:
    vector<int> getLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        vector<int> ans;
        vector<int> dp(n, 1);
        vector<int> parent(n);

        // Initialize parent array so every element points to itself initially
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            // Traverse j strictly left-to-right to guarantee earliest indices
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    // Only update if it is STRICTLY greater. 
                    // This ignores later ties, keeping the earliest index!
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j; // Drop a breadcrumb
                    }
                }
            }
        }

        int len = INT_MIN; 
        int idx = 0;

        // Find the earliest index that holds the maximum length
        for (int i = 0; i < n; i++) {
            if (dp[i] > len) {
                len = dp[i];
                idx = i;
            }
        }

        // Path Reconstruction using the parent breadcrumbs
        int curr = idx;
        while (parent[curr] != curr) {
            ans.push_back(nums[curr]);
            curr = parent[curr];
        }
        ans.push_back(nums[curr]); // Push the final starting element

        reverse(ans.begin(), ans.end());

        return ans;
    }
};