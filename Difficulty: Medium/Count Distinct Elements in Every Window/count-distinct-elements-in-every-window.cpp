class Solution {
	public:
	vector<int>countDistinct(vector<int> &arr, int k) {
		vector<int>ans;
		unordered_map<int, int>mp;
		int n = arr.size();
		for (int i = 0; i<k; i++) {
			mp[arr[i]]++;
		}
		int l = 0, r = k - 1;
		while (r<n) {
			ans.push_back(mp.size());
			mp[arr[l]]--;
			
			if (mp[arr[l]] == 0) {
				mp.erase(arr[l]);
			}
			
			l++; r++;
			mp[arr[r]]++;
			
		}
		// 		ans.push_back(mp.size());
		
		return ans;
	}
};
