
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
/* NO.1325 ȿ������ ��ŷ */
int** graph;												// ��� �� ���踦 ǥ���ϴ� Graph
int* visited;												// �湮 ��� üũ�ϴ� Arr
int* virusedArr;											// ������ ��� ���� �����ϴ� Arr
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
			// ����Ǿ� �ְ� + �湮���� ���� ���
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
	// graph �ʱ�ȭ (N X N)
	graph = new int*[n + 1];
	visited = new int[n + 1];
	virusedArr = new int[n + 1];

	memset(visited, 0, sizeof(int) * (n + 1));
	memset(virusedArr, 0, sizeof(int) * (n + 1));
	for (int i = 0; i < n + 1; i++) {
		graph[i] = new int[n + 1];
		memset(graph[i], 0, sizeof(int) * (n + 1));
	}
	// M���� �ŷڰ��踦 �޾� graph ä���
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[y][x] = 1;
	}

	//print_graph();			// print
	//print_visited();


	// BFS ���� �� ����
	if (m == 0)						// ������ ���� ���
		return 0;
	else {
		for (int i = 0; i < n; i++) {	// N�� �ݺ� 
			int num;

			q.push(i + 1);
			visited[i + 1] = 1;
			num = BFS();
			//cout << "������ ��:" << num << endl;
			virusedArr[i + 1] = num;									// ������ ��� �� ����
			if (num > max)
				max = num;
			memset(visited, 0, sizeof(int) * (n + 1));					// visited �ʱ�ȭ
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