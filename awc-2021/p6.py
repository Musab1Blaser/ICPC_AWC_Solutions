# Logic was built here - TLEs on Codedrills


def find(dsu, i):
    if dsu[i] != i:
        dsu[i] = find(dsu, dsu[i])
    return dsu[i]

def join(dsu, sz, i, j):
    a = find(dsu, i)
    b = find(dsu, j)
    if a != b:
        if sz[a] < sz[b]:
            a, b = b, a
        sz[a] += sz[b]
        dsu[b] = dsu[a]
        return 1
    return 0

for _ in range(int(input())):
    n, m = map(int, input().split())
    c = []
    valid = 1
    for i in range(n):
        c.append(list(map(int, input().split())))
        if c[-1][0] != 1:
            valid = 0
    if not valid:
        print(-1)
        continue
    
    # graph = {i:[] for i in range(n)}
    edges = []
    dsus = [[i for i in range(n-j)] for j in range(n)]
    szs = [[1 for i in range(n-j)] for j in range(n)]
    ccs = [1 for _ in range(n)]
    edges = set()
    potential_edges = set()
    non_edges = set()
    for k in range(1, n):
        for i in range(n-k):
            ccs[i] += 1 # assume not connected
            for j in range(k-1): # check all the things other than i that i+k is connected to
                if find(dsus[i+1], j) == find(dsus[i+1], k-1):
                    
                    ccs[i] -= join(dsus[i], szs[i], j+1, k)
                
            if c[i][k] != ccs[i]:     
                ccs[i] -= join(dsus[i], szs[i], 0, k)
                edges.add((i+1, i+k+1))
            elif find(dsus[i], 0) != find(dsus[i], k):
                non_edges.add((i+1, i+k+1))
            if c[i][k] != ccs[i]:
                valid = 0
    
    for i in range(n):
        for j in range(i):
            if len(edges) < m and (j+1, i+1) not in non_edges:
                edges.add((j+1, i+1))
    
    if not valid or len(edges) != m:
        print(-1)
    else:
        edges = list(edges)
        edges.sort()
        for edge in edges:
            print(*edge)