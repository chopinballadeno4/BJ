import sys
input = sys.stdin.readline
from collections import deque

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def bfs(graph,R,C):
    #queue=deque()
    #check=[[False]*C for _ in range(R)]
    queue=set([(0,0,1,graph[0][0])]) # queue 사용이 아닌 set 사용 ★★★★★
    #queue.append((0,0,1,graph[0][0]))
    #check[0][0]= True
    max=1

    while queue:
        x, y, n, stringstack = queue.pop() # queue 사용이 아닌 set 사용 ★★★★★
        if n > max: max=n
        for i in range(4):
            px=x+dx[i]
            py=y+dy[i]
            if 0<=px<R and 0<=py<C:
                #if check[px][py]==False:
                graphstr=graph[px][py]
                if graphstr not in stringstack:
                    #queue.append((px,py,n+1,stringstack+graphstr))
                    queue.add((px,py,n+1,stringstack+graphstr))
                    #check[px][py]=True

    print(max)

if __name__ == "__main__":
    R,C = map(int,input().strip().split())
    graph=[]
    for _ in range(R):
        graph.append(list(input()))

    bfs(graph,R,C)
