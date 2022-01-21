#include <iostream>
#include <string>
#include <stack>
using namespace std;
enum Mode { WORD, TAG, TAG_START, TAG_END, RESET };
string S;

int main() {
	getline(cin, S);
	string result;
	Mode mode = WORD;
	stack<int> wordContainer;
	for (int i = 0; i < S.length(); i++) {
		char c = S[i];
		switch (c) {
		case '<':
			mode = TAG_START;
			break;
		case '>':
			mode = TAG_END;
			break;
		case ' ':
			if (mode != TAG && mode != TAG_START) mode = RESET;
			else mode = TAG;
			break;
		default:
			if (mode != TAG && mode != TAG_START) mode = WORD;
			else mode = TAG;
			break;
		}

		switch (mode) {
		case RESET:
		case TAG_START:
			// stack�� ��Ƴ��� �ܾ ������ result�� ����
			while (wordContainer.size()) {
				result += wordContainer.top();
				wordContainer.pop();
			}
			result += c;
			break;
		case TAG_END:
			result += c;
			mode = WORD;
			break;
		case TAG:
			result += c;
			break;
		case WORD:
			wordContainer.push(c); // �Ųٷ� �����ϱ� ���Ͽ� stack�� �ܾ��� �� ���ھ� ����
			break;
		}
	}

	// stack�� ��Ƴ��� �ܾ ������ result�� ����
	while (wordContainer.size()) {
		result += wordContainer.top();
		wordContainer.pop();
	}

	cout << result << '\n';

	return 0;
}