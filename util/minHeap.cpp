#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

/**
 * 	Priority queue is by default max heap.
 * 
 * */
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0) {};
	ListNode(int x) : val(x), next(NULL) {};
	ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class myComparator {
public:
	int operator() (const ListNode *l1, const ListNode *l2) {
		if(l1->val > l2->val) {
			return true;
		}
		return false;
	}
};

int main() {
	priority_queue<ListNode*, vector<ListNode *>, myComparator> minHeap;

	return 0;
}








