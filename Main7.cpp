#include <iostream>

typedef long long ll;
#define endl "\n"
#define MAX 201
#define Moduler 1000000000
using namespace std;

int N,K;
ll DP[MAX][MAX];

void Input() {
    cin >> N >> K;
}
 // DP[a][b] = c 의 의미는 "a개 더해서 그 합이 b가 되는 경우의 수는 c개 입니다."

void Solution() {
    for(int i=0 ; i<=N ; i++) {
        DP[1][i] =1;
    }

    for(int k=2 ; k<=K ; k++) {
        for(int n=0 ; n<=N ; n++) {
            for(int i=0 ; i<=n ; i++) {
                DP[k][n] = DP[k][n] + DP[k-1][i];
            }
            DP[k][n] = DP[k][n] % Moduler;
        }
    }

    cout << DP[K][N] << endl;
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
