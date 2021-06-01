"""
18870 좌표압축 문제 (List)
- set을 통해 중복을 해결하고 , dict에 저장해서 순위를 찾자 !
"""

N=int(input())
arr=list(map(int,input().split()))

arr2=sorted(list(set(arr))) # arr2는 정렬된 배열
dic = {arr2[i] : i for i in range(len(arr2))} # dic에 정렬되어있는 arr2의 값을 key로 순위 i를 value로
for i in arr: # arr를 하나씩 꺼내서
    print(dic[i], end=' ') # 순위 찾기
