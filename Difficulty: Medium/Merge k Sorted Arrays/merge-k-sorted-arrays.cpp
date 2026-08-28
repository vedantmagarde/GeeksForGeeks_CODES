class Solution {
	public:
	vector<int> mergeArrays(vector<vector<int>> &mat) {
		int r = mat.size();
		int c = mat[0].size();
		vector<int>ans;
		vector<int>idx(r, 0);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
		for (int i = 0; i<r; i++) {
			pq.push({mat[i][0], i});
		}
		while (1) {
			int ele = pq.top().first;
			int index = pq.top().second;
			pq.pop();
			
			ans.push_back(ele);
			idx[index]++;
			
			if (idx[index]<c)
				pq.push({mat[index][idx[index]], index});
			
			if (pq.empty())break;
		}
		return ans;
	}
};
