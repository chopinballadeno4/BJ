#include<iostream>
#include<queue>

#define endl "\n"; // 줄바꿈선 endl로 정의하기
#define MAX 50
using namespace std;

int R, C;
int water_map[MAX][MAX];
char map[MAX][MAX];
bool visit[MAX][MAX];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

pair<int, int> Start_pos, End_pos; // .first , .end 로 접근
queue<pair<int, int>> water_q;

void Input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			water_map[i][j] = 999;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				Start_pos.first = i;
				Start_pos.second = j;
			}
			else if (map[i][j] == 'D') {
				End_pos.first = i;
				End_pos.second = j;
			}
			else if (map[i][j] == '*') {
				water_map[i][j] = 0; // 물있는곳은 0부터 
				water_q.push(make_pair(i, j)); //큐에 pair을 만들어서 push
			}
		}
	}
}

void Make_watermap() {
	while (water_q.empty() == 0) { //비어있지 않으면
		int Qs = water_q.size();
		for (int i = 0; i < Qs; i++) {
			int x = water_q.front().first;
			int y = water_q.front().second;
			water_q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
					if (map[nx][ny] == '.') {
						if (water_map[nx][ny] > water_map[x][y] + 1) {
							water_map[nx][ny] = water_map[x][y] + 1; // 점점확장되는 부분은 1씩 더해서 계산 ★★★★★★★★★★★★
							water_q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
}

/*
여기 그래프에서 물이 분단위로 1씩 커지게 값을 설정해놓았음
그리고 너구리가 움직일때 water_map[nx][ny] > Cnt + 1 이러한 옵션을 주었음
물도 분단위로 확장이되고 , 너구리도 분단위로 움직이므로 물확장보다 더 빠르게 움직이지 않게 하기 위함임 
*/

void Move() {
	queue<pair<pair<int, int>, int>> Q;
	Q.push(make_pair(make_pair(Start_pos.first, Start_pos.second), 0));
	visit[Start_pos.first][Start_pos.second] = true;

	while (Q.empty() == 0) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int Cnt = Q.front().second;
		Q.pop();

		if (x == End_pos.first && y == End_pos.second) {
			cout << Cnt << endl;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
        
				if (visit[nx][ny] == false && map[nx][ny] != 'X' && water_map[nx][ny] > Cnt + 1) {
					visit[nx][ny] = true;  // 1분뒤에 너구리가 이동한 부분보다 물이 늦게 와야 하므로 ★★★★★★★★★★★
					Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
				}
			}
		}
		cout << "KAKTUS" << endl;
	}

}

void Solution() {
	Make_watermap();
	Move();
}

void Solve() {
	Input();
	Solution();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();
	return 0;
}

