from sys import stdin, stdout
read = lambda: stdin.readline().strip()
tok = lambda: map(int, read().split())

r,c = tok()
sy,sx = tok()
ey,ex = tok()

grid = [list(read()) for i in xrange(r)]
visited = []

grid[sy][sx] = 0
queue = [(sy,sx)]
nqueue = []
steps = 0
valid = lambda y,x: ((0<=y<r) and (0<=x<c) and (grid[y][x]=='O'))

while queue and grid[ey][ex] == 'O':
    nqueue = queue[:]
    queue = []
    steps += 1
    for (y,x) in nqueue:
        if valid(y+1,x):
            grid[y+1][x] = steps
            queue.append((y+1,x))

        if valid(y-1,x):
            grid[y-1][x] = steps
            queue.append((y-1,x))

        if valid(y,x+1):
            grid[y][x+1] = steps
            queue.append((y,x+1))

        if valid(y,x-1):
            grid[y][x-1] = steps
            queue.append((y,x-1))

n = 10000
for i in xrange(int(read())):
    y,x = tok()
    n = min(n, grid[y][x])

if type(grid[ey][ex]) == str or n > grid[ey][ex]:
    stdout.write("-1\n")
else:
    stdout.write(str(grid[ey][ex]-n)+'\n')
