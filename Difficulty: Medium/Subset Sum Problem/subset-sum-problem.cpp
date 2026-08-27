class Solution {
	public:
	
	bool fun(vector<int>& arr, int sum, int idx, vector<vector<int>> &dp) {
		if (sum == 0)return true;
		
		if (idx >= arr.size())return false;
		
		if (dp[sum][idx] != -1)return dp[sum][idx];
		bool skip = fun(arr, sum, idx + 1, dp);
		bool take = false;
		if (sum - arr[idx] >= 0)
			take = fun(arr, sum - arr[idx], idx + 1, dp);
		
		return dp[sum][idx] = skip || take;
	}
	bool isSubsetSum(vector<int>& arr, int sum) {
		int n = arr.size();
		vector<vector<int>> dp(sum + 1, vector<int>(n + 1, -1));
		return fun(arr, sum, 0, dp);
	}
};
