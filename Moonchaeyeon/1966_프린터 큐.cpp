#include <iostream>
#include <vector>
#include <queue>
using namespace std;
unsigned int NT, N, M;

int main() {
	cin >> NT; // test case ����
	for (int i = 0; i < NT; i++) {
		cin >> N >> M;
		queue<vector<int>> priority_info; // [idx, priority] list�� ����
		priority_queue<int> max_priorityq; // �켱����

		for (int idx = 0; idx < N; idx++) { // priority�� �޾ƿ�
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
			if (currItem[1] == max_priorityq.top()) { // ���� �켱������ ���� ��
				printNum++; // print ��Ŵ
				max_priorityq.pop();
				if (currItem[0] == M) break; // ���� ã���� �ϴ� �������� ��������� ����
			}
			else {
				priority_info.push(currItem); // �ڿ� ����
			}
			priority_info.pop(); // �������� �����ϱ�
		}
		cout << printNum << '\n';
	}

	return 0;
}