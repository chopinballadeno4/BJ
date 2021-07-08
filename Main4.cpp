#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

const int MAX = 100000 +1 ;
bool visited[MAX];

int minSecond(int N, int K) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

    q.push(make_pair(0,n)); // 시간 , 누나 위치
    visited[N]=true;

    while(!q.empty()) {
        int curSec = q.top().fisrt;
        int curLoc = q.top().second;
        q.pop();
        
        if(curLoc == K) return curSec; // 목적지 도달시

        if(curLoc*2 < MAX && !visited[curLoc]) {
            q.push(make_pair(curSec,curLoc*2));
            visited[curLoc*2] = true;
        }
        if(curLoc+1 < MAX && !visited[curLoc+1]) {
            q.push(make_pair(curSec+1,curLoc+1));
            visited[curLoc+1] = true;
        }
        if(curLoc-1 >= 0 && !visited[curLoc-1]) {
            q.push(make_pair(curSec+1,curLoc-1));
            visited[curLoc-1] = true;
        }

    }
}

int main(void) {
    int N,K;
    cin >> N >> K;
    cout << minSecond(N,K) << "\n";
    return 0;
}

/* 파이썬 코드
import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()
n, k = map(int, input().split()) # n 은 누나위치 , k 는 동생위치
d = [int(1e9)] * 100_001
q = deque([(n, 0)])
d[n] = 0 # 누나 시작위치는 0으로
while q:
    i, t = q.popleft() # i 는 위치 , t 는 시간
    for ni in [i-1, i+1, 2*i]:
        nt = t if ni == 2*i else t+1 # 만약 2*i 라면 nt 는 변화없음 , 2*i 가 아니라면 1초증가 if문 한줄로쓰기
        if 0 <= ni <= 100_000 and d[ni] > nt:
            d[ni] = nt
            q.append((ni, nt))

print(d[k])
*/
