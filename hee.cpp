/*
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

/* NO.1325 효율적인 해킹 (다른이 참고 버젼으루) 

vector<int> computer[10000 + 1];						// 컴퓨터별 감염 No
int N, M;												// N: 컴퓨터No, M: 조건개수
int max = -1;											// 감염된 최고개수
vector<int> result(10001, 0);							// 각 컴퓨터별 감염개수
queue<int> queue;
int visit[10000 + 1] = {0, };

void BFS() {
	for (int i = 1; i <= N; i++) {
		visit[10000 + 1] = { 0, };
		queue.push(i);
		visit[i] = 1;
		
		while (!queue.empty()) {
			int now = queue.front();
			queue.pop();
			
			for (int j = 0; j < computer[now].size(); j++) {
				queue.push(computer[now][j]);
				visit[computer[now][j]] = 1;
				result[i]++;
			}
		}

		if (result[i] > max)
			max = result[i];
	}
	// result 백터의 최고 감염된 computer 뽑기
	for (int i = 1; i <= result.size(); i++) {
		if (result[i] == max)
			cout << i;
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {		// 조건 수만큼 반복
		int start, end;
		cin >> end >> start;
		computer[start].push_back(end);
	}

	BFS();

	return 0;
}*/