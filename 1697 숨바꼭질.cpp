#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
/* NO.1697 숨바꼭질 (size만큼 for문을 돌아야 하는데 81 size에서 27만큼 돌아버려서 이전 queue 정보를 지우지 않네 ..*/
using namespace std;

queue<int> line;
int N, K;
int cnt = 0;							// 답 

void print_queue(int size) {
	queue<int> que;
	que = line;

	cout << "=== Queue 값 확인 ===   CNT:" << cnt  <<" Que 사이즈:"<< size <<endl;
	while (!que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl << "=== ======= ===" << endl;

}

void BFS() {
	line.push(N);
	// 한번에 N과 K 위치가 같을경우
	if (N == K)
		return;
	else{
		line.pop();

		line.push(N - 1);
		line.push(N + 1);
		line.push(2 * N);
		cnt++;
	}

	while (1) {
		int size = line.size();
		//print_queue(size);
		for (int i = 0; i < size; i++) {
			int now = line.front();
			line.pop();
			// queue에 값을 확인하여 K와 비교, 값이 범위를 넘어가는 경우 queue에서 다음 경우의 수 고려X , 그 외 다음 3가지 경우의 수 고려
			if (now == K) {
				// 정답이요
				break;
			}
			else if (now < 0 || now > 100000)
				continue;
			else {
				// 3가지 경우의 수 모두 Queue에 삽입.
				line.push(now - 1);
				line.push(now + 1);
				line.push(2 * now);
			}
		}	
		cnt++;
	}
}

int main() {
	cin >> N >> K;
	
	BFS();
	cout << "정답:" << cnt;

	return 0;
}