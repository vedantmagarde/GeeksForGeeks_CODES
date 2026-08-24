class Solution {
	public:
	
	int fun(vector<int>& nums, int prev, int curr, vector<vector<int>> & dp) {
		if (curr == nums.size())
			return 0;
		
		if (dp[prev + 1][curr] != -1)
			return dp[prev + 1][curr];
		int skip = fun(nums, prev, curr + 1, dp);
		int take = 0;
		
		if (prev == -1 || nums[prev] < nums[curr]) {
			take = nums[curr] + fun(nums, curr, curr + 1, dp);
		}
		
		return dp[prev + 1][curr] = max(skip, take);
	}
	
	int maxSumIS(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> dp(n + 5, vector<int>(n + 5, -1));
		return fun(nums, -1, 0, dp);
		
	}
};
