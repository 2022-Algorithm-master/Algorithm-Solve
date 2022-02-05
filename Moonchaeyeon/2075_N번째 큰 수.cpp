#include <iostream>
#include <functional>
#include <queue>
using namespace std;
int N;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int i, j;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq; // min heap

	int value;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> value;
			pq.push(value);
			if (pq.size() > N) // N보다 커지면
				pq.pop(); // 지금 가장 작은 값을 pop -> 개수를 N개로 맞춤
		}
	}
	
	cout << pq.top() << '\n'; // 지금 가장 큰 값이 N번째로 가장 큰 값임

	return 0;
}