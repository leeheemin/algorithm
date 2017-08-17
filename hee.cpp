
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
/* NO.1325 효율적인 해킹 */
int** graph;												// 노드 간 관계를 표현하는 Graph
int* visited;												// 방문 노드 체크하는 Arr
int* virusedArr;											// 감염된 노드 수를 저장하는 Arr
queue<int> q;
int n, m;

void print_graph() {
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

void print_visited() {
	for (int i = 0; i < n + 1; i++) {
		cout << visited[i] << " ";
	}
}

void print_answer(int max) {
	for (int i = 1; i < n + 1; i++) {
		if (virusedArr[i] == max)
			cout << i << " ";
	}

}

int BFS() {
	int virused = 1;

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int next = 1; next < n + 1; next++) {
			// 연결되어 있고 + 방문한적 없는 노드
			if (graph[current][next] && !visited[next]) {
				visited[next] = 1;
				q.push(next);
				virused++;
			}
		}

	}

	return virused;
}

int main() {
	int max = -1;

	cin >> n >> m;
	// graph 초기화 (N X N)
	graph = new int*[n + 1];
	visited = new int[n + 1];
	virusedArr = new int[n + 1];

	memset(visited, 0, sizeof(int) * (n + 1));
	memset(virusedArr, 0, sizeof(int) * (n + 1));
	for (int i = 0; i < n + 1; i++) {
		graph[i] = new int[n + 1];
		memset(graph[i], 0, sizeof(int) * (n + 1));
	}
	// M개의 신뢰관계를 받아 graph 채우기
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[y][x] = 1;
	}

	//print_graph();			// print
	//print_visited();


	// BFS 시작 전 셋팅
	if (m == 0)						// 조건이 없는 경우
		return 0;
	else {
		for (int i = 0; i < n; i++) {	// N번 반복 
			int num;

			q.push(i + 1);
			visited[i + 1] = 1;
			num = BFS();
			//cout << "감염된 수:" << num << endl;
			virusedArr[i + 1] = num;									// 감염된 노드 수 저장
			if (num > max)
				max = num;
			memset(visited, 0, sizeof(int) * (n + 1));					// visited 초기화
		}
	}
	print_answer(max);
	//

	//delete
	for (int i = 0; i < n + 1; i++)
		delete[] graph[i];
	delete[] graph;

	return 0;
}