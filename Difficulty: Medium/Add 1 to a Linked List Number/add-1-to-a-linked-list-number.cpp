class Solution {
	public:
	Node* addOne(Node* head) {
		Node*temp = head;
		int len = 0;
		vector<int>arr;
		while (temp) {
			arr.push_back(temp->data);
			len++;
			temp = temp->next;
		}
		
		int i = arr.size() - 1;
		int rem = 0;
		while (i >= 0) {
			arr[i] = arr[i]+1;
			rem = arr[i]/10 ;
			arr[i] = arr[i]%10;
			if (rem == 0) {
				break;
			}
			i--;
		}
		
		Node*a = head;
		int itr = 0;
		while (a) {
			a->data = arr[itr++];
			a = a->next;
		}
		if (rem != 0) {
			Node*t = new Node(rem);
			t->next = head;
			head = t;
		}
		
		return head;
	}
};
