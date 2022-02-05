#include <iostream>
#include <vector>
#include <queue>
using namespace std;
unsigned int NT, N, M;

int main() {
	cin >> NT; // test case 개수
	for (int i = 0; i < NT; i++) {
		cin >> N >> M;
		queue<vector<int>> priority_info; // [idx, priority] list를 저장
		priority_queue<int> max_priorityq; // 우선순위

		for (int idx = 0; idx < N; idx++) { // priority를 받아옴
			vector<int> idx_priority(2);
			int p;
			cin >> p;
			idx_priority[0] = idx;
			idx_priority[1] = p;
			priority_info.push(idx_priority);
			max_priorityq.push(p);
		}
		
		int printNum = 0;
		while (priority_info.size()) {
			vector<int> currItem = priority_info.front();
			if (currItem[1] == max_priorityq.top()) { // 가장 우선순위가 높을 때
				printNum++; // print 시킴
				max_priorityq.pop();
				if (currItem[0] == M) break; // 내가 찾고자 하는 아이템을 출력했으면 종료
			}
			else {
				priority_info.push(currItem); // 뒤에 넣음
			}
			priority_info.pop(); // 아이템을 제거하기
		}
		cout << printNum << '\n';
	}

	return 0;
}