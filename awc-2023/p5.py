for _ in range(int(input())):
    n = int(input())
    if n == 3:
        print(1, 2)
        print(1, 2)
        continue
    if n == 5:
        print(2, 3)
        print(1, 2, 5)
        print(4, 3, 0)
        continue
    if n%2:
        print(-1)
        continue
    k = n//2
    grid = [[0]*k for _ in range(k)]
    for i in range(k): # rows
        for j in range(k): # columns
            grid[i][j] =  ((i + j) % k)*k + (2*i + j) % k
    print(k, k)
    for row in grid:
        print(*row)
        
    # for row in grid:
    #     print(row, sum(row))
    # for col in range(k):
    #     print(sum([grid[i][col] for i in range(k)]), end=" ")
    # print()