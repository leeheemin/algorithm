
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;
/* NO.2206 벽 부수고 이동하기 */ /* 입력값이 붙어있는거 + 생성자 new생성 or 그냥 .. 포인터 .. */
char map[1001][1001];											// Map Graph
int N, M;
int max = -1;

class Node {		// (x,y) 좌표
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
class Path {		// 경로길에 대한 모든 정보
private:
	Node n;				// (x,y)좌표
	int num;			// 경로 길이 (답)
	bool b;				// 벽을 부쉈는지 여부
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

// (x,y)가 map 안에서 진행 가능한지 판단 여부
bool judge(int x, int y) {
	if (x < 1 || x > 1000 || y < 1 || y > 1000) {
		cout << "[" << x << "," << y << "] - 불가능" << endl;
		return false;		// 불
	}
	else {		// Map 범위내에 벽 유무여부
		if (!map[x][y])
			return true;			// 뚫려있음 가
		else
			return false;			// 막혀있음 불
	}
}

void dfs(Path p) {
	Node n;
	int x; int y; int num;
	bool b;

	n = p.getNode(); x = n.getX(); y = n.getY(); num = p.getNum(); b = p.getB();

	cout << "DFS call [" << x << "," << y << "] num:" << num << ", " << b << endl;
	// 최종 목적지인 경우
	if (x == N && y == M) {
		if (num > max)
			max = num;
		return;
	}

	// 상, 하, 좌, 우 진행
	// 상
	if (judge(x - 1, y)) {
		p.setNode(x - 1, y, num + 1, b);
		dfs(p);
	}
	else {
		if (b)		// 벽을 이미 부쉈다면
			return;
		else {		// 아직 부수지 않았다면
			p.setNode(x - 1, y, num + 1, true);
			dfs(p);
		}
	}
	// 하
	if (judge(x + 1, y)) {
		p.setNode(x + 1, y, num + 1, b);
		dfs(p);
	}
	else {
		if (b)		// 벽을 이미 부쉈다면
			return;
		else {		// 아직 부수지 않았다면
			p.setNode(x + 1, y, num + 1, true);
			dfs(p);
		}
	}
	// 좌
	if (judge(x, y - 1)) {
		p.setNode(x, y - 1, num + 1, b);
		dfs(p);
	}
	else {
		if (b)		// 벽을 이미 부쉈다면
			return;
		else {		// 아직 부수지 않았다면
			p.setNode(x, y - 1, num + 1, true);
			dfs(p);
		}
	}
	// 우
	if (judge(x, y + 1)) {
		p.setNode(x, y + 1, num + 1, b);
		dfs(p);
	}
	else {
		if (b)		// 벽을 이미 부쉈다면
			return;
		else {		// 아직 부수지 않았다면
			p.setNode(x, y + 1, num + 1, true);
			dfs(p);
		}
	}
	return;
}

int main() {
	cin >> N >> M;

	// map 초기화 (N X M)     
	// 입력이 연속으로 받아져서 char형으로?? int형 배열로 선언했을 떄는 띄워쓰기 단위로 받던데 ㅇㅇ  
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			cin >> map[i][j];
		}
	}

	//print_map();			// print

	// DFS 셋팅 및 실행
	Node node = Node(1, 1);
	Path path = Path(node);
	dfs(path);
	cout << max;


	return 0;
}