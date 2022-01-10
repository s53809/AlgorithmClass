#include <iostream>
#include <stack>
#include <ctime>
#include <vector>
#include <cstdlib>
#define HM 10000000
using namespace std;

vector<int> input(HM, 0);
vector<int> output(HM, 0);
vector<bool> duplication_check(HM, false);
stack<int> st;

void randomInput() {
	for (int i = 0; i < HM; i++) {
		int inputNum = rand() % HM;
		/*if (!duplication_check[inputNum]) { //중복 체크 코드 (굳이 안해도 됩니다)
			duplication_check[inputNum] = true;
			input[i] = inputNum;
		}
		else {
			i--;
			continue;
		}*/
		input[i] = inputNum;
	}
}

void exploring() {
	for (int i = 1; i < HM; i++) {
		while (!st.empty()) {
			if (input[st.top()] >= input[i]) {
				output[i] = st.top();
				break;
			}
			else {
				st.pop();
			}
		}
		if (st.empty()) {
			output[i] = -1;
		}
		st.push(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(NULL));
	randomInput();
	clock_t startTime = clock(); // 시작 시간 체크
	st.push(0);
	output[0] = -1; // -1은 레이저가 닿은 곳이 아무것도 없을 때를 의미한다
	exploring();
	clock_t endTime = clock(); // 종료 시간 체크
	clock_t resultTime = endTime - startTime;
	cout << "수행 시간 : " << resultTime << "ms\n";
	cout << "input -------------------\n";
	for (int i = 0; i < HM; i++) {
		cout << input[i] << ", ";
	}
	cout << '\n';
	cout << "output -------------------\n";
	for (int i = 0; i < HM; i++) {
		cout << output[i] << ", ";
	}
	cout << '\n';
}