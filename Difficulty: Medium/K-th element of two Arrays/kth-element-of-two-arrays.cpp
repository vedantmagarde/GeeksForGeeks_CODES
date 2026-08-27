class Solution {
	public:
	int kthElement(vector<int> &a, vector<int> &b, int k) {
		int itr1 = 0, itr2 = 0;
		int n1 = a.size(), n2 = b.size();
		priority_queue<int>pq;
		
		while (itr1 < n1 && itr2<n2 && pq.size()<k) {
			if (a[itr1]<b[itr2]) {
				pq.push(a[itr1]);
				itr1++;
			} else {
				pq.push(b[itr2]);
				itr2++;
			}
		}
		
		while (itr1 < n1 && pq.size()<k) {
			pq.push(a[itr1]);
			itr1++;
		}
		while (itr2 < n2 && pq.size()<k) {
			pq.push(b[itr2]);
			itr2++;
		}
		return pq.top();
		
	}
};
