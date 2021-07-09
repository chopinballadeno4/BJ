#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int room[9][9];
int visited[9][9];
vector<pair<int,int>> v;

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
int best = 1e9;

void check(int y, int x, int i, int num) {
    int ny = y;
    int nx = x;
    while(true) {
        ny = ny+dy[i];
        nx = nx+dx[i];
        if(room[ny][nx]==6) break;
        if(!(ny>=0 && ny<N && nx>=0 && nx<M)) break;
        visited[ny][nx] =visited[ny][nx]+num; 
    }
}

void rotate(int beign, int i, int num) {
    int y= v[begin].first;
    int x= v[begin].second;
    int number=room[y][x];
    
    if (number == 1)
	{
		// 오른쪽
		check(y, x, (i+1)%4, num);
	}
	else if (number == 2)
	{
		int y2 = y;
		int x2 = x;
		// 오른쪽 꺼
		check(y, x, (i + 1)%4, num);
		// 왼쪽 꺼
		check(y, x, (i + 3) % 4, num);
	}
	else if (number == 3)
	{
		// 오른쪽 꺼
		check(y, x, (i + 1) % 4, num);
		// 위쪽꺼 꺼
		check(y, x, (i + 0) % 4, num);
	}
	else if (number == 4)
	{
		// 오른쪽 꺼
		check(y, x, (i + 1) % 4, num);
		// 위쪽꺼 꺼
		check(y, x, (i + 0) % 4, num);
		//왼쪽꺼
		check(y, x, (i + 3) % 4, num);
	}
	else if (number == 5) {
		// 오른쪽 꺼
		check(y, x, (i + 1) % 4, num);
		// 위쪽꺼 꺼
		check(y, x, (i + 0) % 4, num);
		//왼쪽꺼
		check(y, x, (i + 3) % 4, num);
		// 아래꺼
		check(y, x, (i + 2) % 4, num);
	}
}

void solve(int begin) {
    if(begin > v.size() -1) { // v 벡터는 cctv point 저장 벡터
        int cnt=0;
        for(int i=0 ; i<N ; ++i) {
            for(int j=0 ; j<N ; ++j) {
                if(visited[i][j]==0) cnt++;
            }
        }
        best = min(best,cnt);
        return ;
    }

    for(int i=0 ; i<4 ; ++i) {
        rotate(begin,i,1); //회전시키고
        solve(begin+1);
        rotate(begin,i,-1); //되돌리는 구조
    }

}

int main() {
    cin >> N >> M;
    for(int i=0 ; i<N ; ++i) {
        for(int j=0 ; j<M ; ++j) {
            cin >> room[i][j];

            if(room[i][j] !=0 && room[i][j] != 6) {
                v.push_back({i,j});
                visited[i][j] = room[i][j];
            }
            if(room[i][j]==6) visited[i][j]=6;
        }
    }

    if(v.size()==0) {
        int cnt =0;
        for(int i=0 ; i<N ; ++i) {
            for(int j=0 ; j<M ; ++j) {
                if(room[i][j]==0) cnt++;
            }
        }
        cout << cnt << "\n";
        return 0;
    } else {
        solve(0);
        cout << best << "\n";
    }
    return 0;
}

/*  이건 동센세 파이썬 코드
import sys
import heapq
from collections import deque
from itertools import combinations, permutations
from copy import deepcopy
input = lambda: sys.stdin.readline().rstrip() 

test = True
if test:
    try:
        sys.stdin = open('input_data.txt', 'r')
        print('sys.stdin = input.txt')
    except FileNotFoundError:
        pass

directions = \
[
    [],
    [
        [(-1, 0)],
        [(1, 0)],
        [(0, 1)],
        [(0, -1)]
    ],
    [
        [(-1, 0), (1, 0)],
        [(0, 1), (0, -1)]
    ],
    [
        [(-1, 0), (0, 1)],
        [(0, 1), (1, 0)],
        [(1, 0), (0, -1)],
        [(0, -1), (-1, 0)]
    ],
    [
        [(0, -1), (-1, 0), (0, 1)],
        [(-1, 0), (0, 1), (1, 0)],
        [(0, 1), (1, 0), (0, -1)],
        [(1, 0), (0, -1), (-1, 0)]
    ],
    [
        [(0, 1), (0, -1), (1, 0), (-1, 0)]
    ]
]
n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
cctvs = []
for i in range(n):
    for j in range(m):
        if board[i][j] == 6:
            board[i][j] = -5
        elif 1 <= board[i][j] <= 5:
            cctvs.append((i, j))
def set(ds, x, y, i):
    for dx, dy in ds:
        nx, ny = x + dx, y + dy
        while 0 <= nx < n and 0 <= ny < m:
            if board[nx][ny] == -5: break
            if board[nx][ny] < 1 or board[nx][ny] > 5: 
                board[nx][ny] += i
            nx, ny = nx + dx, ny + dy

def check():
    cnt = 0
    for i in range(n):
        for j in range(m):
            if board[i][j] == 0:
                cnt += 1
    return cnt

min_size = int(1e9)

def dfs(i):
    global min_size
    if i == len(cctvs):
        min_size = min(min_size, check())
        return
    cx, cy = cctvs[i]
    ct = board[cx][cy]
    for direction in directions[ct]:
        set(direction, cx, cy, 10)
        dfs(i+1)
        set(direction, cx, cy, -10)
dfs(0)
print(min_size)
*/
