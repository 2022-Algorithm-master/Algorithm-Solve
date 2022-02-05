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
		if (num) // 0이 아닌 숫자가 입력되었다면
			pq.push(num);
		else { // 0이 입력되었다면
			if (pq.size()) { // 길이가 0이 아니라면
				cout << pq.top() << '\n';
				pq.pop();
			}
			else cout << 0 << '\n'; // 길이가 0일 때
		}
	}

	return 0;
}