#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
/* NO.1697 ���ٲ��� (size��ŭ for���� ���ƾ� �ϴµ� 81 size���� 27��ŭ ���ƹ����� ���� queue ������ ������ �ʳ� ..*/
using namespace std;

queue<int> line;
int N, K;
int cnt = 0;							// �� 

void print_queue(int size) {
	queue<int> que;
	que = line;

	cout << "=== Queue �� Ȯ�� ===   CNT:" << cnt  <<" Que ������:"<< size <<endl;
	while (!que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl << "=== ======= ===" << endl;

}

void BFS() {
	line.push(N);
	// �ѹ��� N�� K ��ġ�� �������
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
			// queue�� ���� Ȯ���Ͽ� K�� ��, ���� ������ �Ѿ�� ��� queue���� ���� ����� �� ���X , �� �� ���� 3���� ����� �� ���
			if (now == K) {
				// �����̿�
				break;
			}
			else if (now < 0 || now > 100000)
				continue;
			else {
				// 3���� ����� �� ��� Queue�� ����.
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
	cout << "����:" << cnt;

	return 0;
}