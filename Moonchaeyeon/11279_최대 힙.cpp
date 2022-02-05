#include <iostream>
#include <queue>
using namespace std;
int N;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	priority_queue<int> pq;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num) // 0�� �ƴ� ���ڰ� �ԷµǾ��ٸ�
			pq.push(num);
		else { // 0�� �ԷµǾ��ٸ�
			if (pq.size()) { // ���̰� 0�� �ƴ϶��
				cout << pq.top() << '\n';
				pq.pop();
			}
			else cout << 0 << '\n'; // ���̰� 0�� ��
		}
	}

	return 0;
}