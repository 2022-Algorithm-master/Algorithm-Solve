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
			if (pq.size() > N) // N���� Ŀ����
				pq.pop(); // ���� ���� ���� ���� pop -> ������ N���� ����
		}
	}
	
	cout << pq.top() << '\n'; // ���� ���� ū ���� N��°�� ���� ū ����

	return 0;
}