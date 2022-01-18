#include <iostream>
#include <queue>
#include <vector>
using namespace std;
unsigned int N, K;

int main() {
	cin >> N >> K;

	queue<int> peopleArr;
	vector<int> yoseArr;

	// �ʱⰪ setting
	for (int i = 1; i <= N; i++)
		peopleArr.push(i);

	int turn = 1 % K;
	while (peopleArr.size() > 0) { // ���� ���� : ���� ����� 0�� �̻��϶����� ���� ����
		if (turn != 0) {
			peopleArr.push(peopleArr.front()); // �ٽ� �迭�� �߰���Ŵ
		}
		else { // ���� �� �����̸�
			yoseArr.push_back(peopleArr.front()); // yoseArr�� ����
		}
		peopleArr.pop(); // ������ ���Ҹ� ����

		turn ++;
		turn = turn % K;
	}

	// result ���
	cout << "<";
	for (int i = 0; i < yoseArr.size(); i++) {
		if (i != 0) {
			cout << ", ";
		}
		cout << yoseArr[i];
	}
	cout << ">";
	

	return 0;
}