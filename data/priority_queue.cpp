#include <iostream>
#include <queue>
using namespace std;

void decrease(int *arr, int arr_size) {
	// defining priority queue
	priority_queue<int> pq;

	// pushing array sequentially one by one
	for (int i = 0; i < arr_size; i++) {
		pq.push(arr[i]);
	}

	// printing priority queue
	cout << "Priority Queue: ";
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}
	cout << endl;
}


void increase(int *arr, int arr_size) {
	// defining priority queue
	priority_queue<int, vector<int>, greater<int>> pq;

	// pushing array sequentially one by one
	for (int i = 0; i < arr_size; i++) {
		pq.push(arr[i]);
	}

	// printing priority queue
	cout << "Priority Queue: ";
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}
	cout << endl;
}


// driver code
int main()
{
	int arr[] = { 10, 2, 4, 8, 6, 9 };
	// printing array
	cout << "Array: ";
	for (auto i : arr) {
		cout << i << ' ';
	}
	cout << endl;

	decrease(arr, sizeof(arr) / sizeof(arr[0]));
	increase(arr, sizeof(arr) / sizeof(arr[0]));
	

	return 0;
}
