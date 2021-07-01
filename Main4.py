import sys
input = sys.stdin.readline

def dp(A,B): # dp풀때 표를 그려보자 !!
    Asize=len(A)
    Bsize=len(B)
    pane=[[0]*(Asize+1) for _ in range(Bsize+1)]
    for i in range(1,Bsize+1):
        for ii in range(Asize+1):
            if B[i-1] == A[ii-1]:
                pane[i][ii]=pane[i-1][ii-1]+1
            else:
                pane[i][ii]=max(pane[i][ii-1],pane[i-1][ii])

    print(pane[-1][-1])
    #https://happylsm76.tistory.com/entry/%EB%B0%B1%EC%A4%80-9251%EB%B2%88LCS-with-Python


if __name__ == "__main__":
    A=input().strip()
    B=input().strip()
    dp(A,B)

