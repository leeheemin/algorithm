/*
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

/* NO.1325 ȿ������ ��ŷ (�ٸ��� ���� ��������) 

vector<int> computer[10000 + 1];						// ��ǻ�ͺ� ���� No
int N, M;												// N: ��ǻ��No, M: ���ǰ���
int max = -1;											// ������ �ְ���
vector<int> result(10001, 0);							// �� ��ǻ�ͺ� ��������
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
	// result ������ �ְ� ������ computer �̱�
	for (int i = 1; i <= result.size(); i++) {
		if (result[i] == max)
			cout << i;
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {		// ���� ����ŭ �ݺ�
		int start, end;
		cin >> end >> start;
		computer[start].push_back(end);
	}

	BFS();

	return 0;
}*/