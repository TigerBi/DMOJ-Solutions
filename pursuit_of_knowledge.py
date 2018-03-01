from sys import stdin, stdout
tok = lambda: map(int, stdin.readline().split())

n,m,t = tok()
arr = [None]
x = [-1 for i in xrange(n+1)]
visited = [0]
tree = {}

for i in xrange(1,n+1):
    arr.append(x[:])
    visited.append(False)
    tree[i] = []

for i in xrange(m):
    s,e = tok()
    tree[s].append(e)

for j in xrange(1,n+1):
    queue = [j]
    visited = {j}
    steps = 0
    while queue:
        nqueue = queue[:]
        queue = []
        for i in nqueue:
            arr[j][i] = steps*t
            for item in tree[i]:
                if item not in visited:
                    visited.add(item)
                    queue.append(item)
        steps += 1

for i in xrange(int(stdin.readline())):
    s,e = tok()
    if arr[s][e] != -1:
        stdout.write(str(arr[s][e]))
    else:
        stdout.write("Not enough hallways!")
    stdout.write('\n')
