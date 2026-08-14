class Solution {
	public:
	
	bool fun(vector<int>& nums, int total, int i, vector<vector<int>> & dp) {
		if (total == 0)
			return true;
			
		if (i >= nums.size())
			return false;
		
		
		if (dp[i][total] != -1)
			return dp[i][total];
		
		bool take=false;
		if (total - nums[i] >= 0)
			take = fun(nums, total - nums[i], i + 1, dp);
		bool skip = fun(nums, total, i + 1, dp);
		
		return dp[i][total] = take || skip;
	}
	
	bool checkSubsequenceSum(vector<int>& nums, int k) {
		
		vector<vector<int>> dp(nums.size() + 5, vector<int>(k + 5, -1));
		return fun(nums, k, 0, dp);
	}
};
