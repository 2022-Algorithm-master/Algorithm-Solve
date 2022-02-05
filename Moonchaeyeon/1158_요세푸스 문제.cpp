#include <iostream>
#include <queue>
#include <vector>
using namespace std;
unsigned int N, K;

int main() {
	cin >> N >> K;

	queue<int> peopleArr;
	vector<int> yoseArr;

	// 초기값 setting
	for (int i = 1; i <= N; i++)
		peopleArr.push(i);

	int turn = 1 % K;
	while (peopleArr.size() > 0) { // 실행 조건 : 남은 사람이 0명 이상일때에만 루프 실행
		if (turn != 0) {
			peopleArr.push(peopleArr.front()); // 다시 배열에 추가시킴
		}
		else { // 빼야 할 아이이면
			yoseArr.push_back(peopleArr.front()); // yoseArr에 저장
		}
		peopleArr.pop(); // 마지막 원소를 제거

		turn ++;
		turn = turn % K;
	}

	// result 출력
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