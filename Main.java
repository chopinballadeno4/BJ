/*
2206 벽부수기 문제 ( BFS )
- 객체로 거리 , 벽을 부쉈는지 기록하자 !
 */

import java.util.*;
import java.io.*;


class Place {
    int y;
    int x;
    int dis;
    int drill;

    Place(int y,int x, int dis, int drill){
        this.y=y;
        this.x=x;
        this.dis=dis;
        this.drill=drill;
    }
}

public class Main {
    static int [] dy = {-1,1,0,0};
    static int [] dx = {0,0,-1,1};
    static int N,M,ans;
    static int [][] map, visit;

    static void bfs(int y, int x){
        Queue<Place> q = new LinkedList<>();
        q.add(new Place(y,x,1,0));
        visit[y][x]=0;

        while(!q.isEmpty()){
            Place p = q.poll();

            if(p.y==N-1 && p.x==M-1){ // 만약에 종착지에 도착하면
                ans=p.dis;
                break;
            }

            for(int i=0 ; i<4 ; i++){
                int nx=p.y+dy[i];
                int ny=p.x+dx[i];

                if(ny<0 || nx<0 || ny >=N || nx>=M) continue;
                if(visit[ny][nx]<=p.drill) continue;

                if(map[ny][nx]==0){ //벽이 아니라면
                    visit[ny][nx]=p.drill; //공사 횟수 그래프에 기록
                    q.add(new Place(ny,nx,p.dis+1,p.drill));
                } else { //벽이라면
                    if(p.drill ==0){ //만약에 공사를 한번도 안조졌으면
                        visit[ny][nx]=p.drill +1;  //벽 조져주고 공사횟수 기록
                        q.add(new Place(ny,nx,p.dis+1,p.drill+1));
                    }
                }
            }
        }
    }

    public static void main(String [] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String [] str = bf.readLine().split(" ");
        N=Integer.parseInt(str[0]);
        M=Integer.parseInt(str[1]);

        map = new int[N][M];
        visit = new int[N][M];

        for(int i=0 ; i<N ; i++){
            str=bf.readLine().split(" ");
            for(int j=0 ; j<M ; j++){
                map[i][j]=Integer.parseInt(str[j]);
                visit[i][j] =Integer.MAX_VALUE;
            }
        }

        ans = Integer.MAX_VALUE;

        bfs(0,0);

        if(ans==Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(ans);
    }
}
