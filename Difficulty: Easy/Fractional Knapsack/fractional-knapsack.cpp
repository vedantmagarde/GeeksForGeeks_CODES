class Solution {
	public:
	double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
		int n = wt.size();
		vector<pair<double, int>> arr;
		for (int i = 0; i<n; i++) {
			double tmp = ((double)val[i])/wt[i];
			arr.push_back({tmp, i});
		}
		
		sort(arr.begin(), arr.end(), [](pair<double, int>&a, pair<double, int>&b) {
			return a.first>b.first;
		});
		
// 		for (int i = 0; i<n; i++) {
// 			cout << arr[i].first << " " << arr[i].second << endl;
// 		}
// 		cout << "hogya";
		
		double ans = 0;
		double W = capacity;
		for (int i = 0; i<n; i++) {
			if (W <= 0)break;
			double ratio = arr[i].first;
			int idx = arr[i].second;
			
			if (W>=wt[idx]) {
				W -= wt[idx];
				ans += val[idx];
			} else if (W<wt[idx]) {
				ans += val[idx]*(((double)W)/wt[idx]);
				W = 0;
			}
		}
		
		return ans;
	}
};
