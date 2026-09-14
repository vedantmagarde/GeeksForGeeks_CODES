class Solution {
	public:
	int minPlatform(vector<int>& arr, vector<int>& dep) {
		
		vector<pair<int, int>> a;
		for (int i = 0; i<arr.size(); i++) {
			a.push_back({arr[i], dep[i]});
		}
		
		sort(a.begin(), a.end(), [&](pair<int, int>a, pair<int, int>b) {
			return a.first<b.first;
		});
		
		priority_queue<int, vector<int>, greater<int>> end_time;
		int itr_a = 0;
		
		while (itr_a<a.size()) {
			if (!end_time.empty() && end_time.top()<a[itr_a].first) {
				end_time.pop();
			}
			
			end_time.push(a[itr_a].second);
			itr_a++;
		}
		
		return end_time.size();
	}
};
