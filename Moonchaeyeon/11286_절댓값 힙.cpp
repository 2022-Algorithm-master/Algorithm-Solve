#include <iostream>
#include <functional>
#include <queue>
using namespace std;
int N;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	priority_queue<int, vector<int>, greater<int>> positive; // �ּ� ��
	priority_queue<int> negative; // �ִ� ��
	cin >> N;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;

		// 1) ����� ��
		if (num > 0)  positive.push(num);

		// 2) ������ ��
		else if (num < 0)  negative.push(num);

		// 3) 0�� ��
		else { 
			if (negative.size()) { // ������ ���� ��
				if (positive.size() && (positive.top() < -negative.top())) { // ����� �����ϰ�, ����� ������ �� �۴ٸ� -> ����� print/pop
					cout << positive.top() << '\n';
					positive.pop();
				}
				else { // ����� �������� �ʰų�, ������ ������ �� �۰ų� ���ٸ� -> ���� print/pop
					cout << negative.top() << '\n';
					negative.pop();
				}
			}
			else { // ������ �������� ���� ��
				if (positive.size()) { // ����� �����Ѵٸ� -> ��� print/pop
					cout << positive.top() << '\n';
					positive.pop();
				}
				else cout << 0 << '\n'; // �ƹ��͵� �������� �ʴ´ٸ� -> 0 print
			}
		}
	}
	return 0;
}