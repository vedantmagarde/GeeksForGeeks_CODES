class Solution {
	public:
	
	int fun(vector<int>& arr, int k, int step, vector<int>&dp) {
		if (step >= arr.size()
			- 1)return 0;
		
		if (dp[step] != -1)return dp[step];
		
		int ans = INT_MAX;
		
		for (int i = step + 1; (i <= step + k) && i<arr.size(); i++) {
			int tmp = abs(arr[step]-arr[i]) + fun(arr, k, i, dp);
			ans = min(ans, tmp);
		}
		
		return dp[step] = ans;
	}
	
	int minimizeCost(int k, vector<int>& arr) {
		vector<int>dp(arr.size() + 10, -1);
		return fun(arr, k, 0, dp);
		
	}
};
