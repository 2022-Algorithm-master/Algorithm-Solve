#include <iostream>
#include <functional>
#include <queue>
using namespace std;
int N;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	priority_queue<int, vector<int>, greater<int>> positive; // 최소 힙
	priority_queue<int> negative; // 최대 힙
	cin >> N;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;

		// 1) 양수일 때
		if (num > 0)  positive.push(num);

		// 2) 음수일 때
		else if (num < 0)  negative.push(num);

		// 3) 0일 때
		else { 
			if (negative.size()) { // 음수가 있을 때
				if (positive.size() && (positive.top() < -negative.top())) { // 양수가 존재하고, 양수의 절댓값이 더 작다면 -> 양수쪽 print/pop
					cout << positive.top() << '\n';
					positive.pop();
				}
				else { // 양수가 존재하지 않거나, 음수의 절댓값이 더 작거나 같다면 -> 음수 print/pop
					cout << negative.top() << '\n';
					negative.pop();
				}
			}
			else { // 음수가 존재하지 않을 때
				if (positive.size()) { // 양수가 존재한다면 -> 양수 print/pop
					cout << positive.top() << '\n';
					positive.pop();
				}
				else cout << 0 << '\n'; // 아무것도 존재하지 않는다면 -> 0 print
			}
		}
	}
	return 0;
}