
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;
/* NO.2206 �� �μ��� �̵��ϱ� */ /* �Է°��� �پ��ִ°� + ������ new���� or �׳� .. ������ .. */
char map[1001][1001];											// Map Graph
int N, M;
int max = -1;

class Node {		// (x,y) ��ǥ
private:
	int x;
	int y;
public:
	Node() {}
	Node(int _x, int _y) {
		x = _x;
		y = _y;
	}
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	int getX() { return x; }
	int getY() { return y; }

};
class Path {		// ��α濡 ���� ��� ����
private:
	Node n;				// (x,y)��ǥ
	int num;			// ��� ���� (��)
	bool b;				// ���� �ν����� ����
public:
	Path(Node _n) {
		n = _n;
		num = 1;
		b = false;
	}
	void setNode(int _x, int _y, int _num, bool _b) {
		n.setX(_x);
		n.setY(_y);
		num = _num;
		b = _b;
	}
	void setB(bool _b) { b = _b; }
	bool getB() { return b; }
	void setNum(int _num) { num = _num; }
	int getNum() { return num; }

	Node getNode() { return n; }

};

void print_map() {
	cout << endl;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

// (x,y)�� map �ȿ��� ���� �������� �Ǵ� ����
bool judge(int x, int y) {
	if (x < 1 || x > 1000 || y < 1 || y > 1000) {
		cout << "[" << x << "," << y << "] - �Ұ���" << endl;
		return false;		// ��
	}
	else {		// Map �������� �� ��������
		if (!map[x][y])
			return true;			// �շ����� ��
		else
			return false;			// �������� ��
	}
}

void dfs(Path p) {
	Node n;
	int x; int y; int num;
	bool b;

	n = p.getNode(); x = n.getX(); y = n.getY(); num = p.getNum(); b = p.getB();

	cout << "DFS call [" << x << "," << y << "] num:" << num << ", " << b << endl;
	// ���� �������� ���
	if (x == N && y == M) {
		if (num > max)
			max = num;
		return;
	}

	// ��, ��, ��, �� ����
	// ��
	if (judge(x - 1, y)) {
		p.setNode(x - 1, y, num + 1, b);
		dfs(p);
	}
	else {
		if (b)		// ���� �̹� �ν��ٸ�
			return;
		else {		// ���� �μ��� �ʾҴٸ�
			p.setNode(x - 1, y, num + 1, true);
			dfs(p);
		}
	}
	// ��
	if (judge(x + 1, y)) {
		p.setNode(x + 1, y, num + 1, b);
		dfs(p);
	}
	else {
		if (b)		// ���� �̹� �ν��ٸ�
			return;
		else {		// ���� �μ��� �ʾҴٸ�
			p.setNode(x + 1, y, num + 1, true);
			dfs(p);
		}
	}
	// ��
	if (judge(x, y - 1)) {
		p.setNode(x, y - 1, num + 1, b);
		dfs(p);
	}
	else {
		if (b)		// ���� �̹� �ν��ٸ�
			return;
		else {		// ���� �μ��� �ʾҴٸ�
			p.setNode(x, y - 1, num + 1, true);
			dfs(p);
		}
	}
	// ��
	if (judge(x, y + 1)) {
		p.setNode(x, y + 1, num + 1, b);
		dfs(p);
	}
	else {
		if (b)		// ���� �̹� �ν��ٸ�
			return;
		else {		// ���� �μ��� �ʾҴٸ�
			p.setNode(x, y + 1, num + 1, true);
			dfs(p);
		}
	}
	return;
}

int main() {
	cin >> N >> M;

	// map �ʱ�ȭ (N X M)     
	// �Է��� �������� �޾����� char������?? int�� �迭�� �������� ���� ������� ������ �޴��� ����  
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			cin >> map[i][j];
		}
	}

	//print_map();			// print

	// DFS ���� �� ����
	Node node = Node(1, 1);
	Path path = Path(node);
	dfs(path);
	cout << max;


	return 0;
}