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
			// stack에 담아놨던 단어를 꺼내서 result에 저장
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
			wordContainer.push(c); // 거꾸로 저장하기 위하여 stack에 단어의 한 문자씩 담음
			break;
		}
	}

	// stack에 담아놨던 단어를 꺼내서 result에 저장
	while (wordContainer.size()) {
		result += wordContainer.top();
		wordContainer.pop();
	}

	cout << result << '\n';

	return 0;
}