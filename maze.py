r = c = charmap = levels = None

def valid(y, x):
    return (0 <= y < r and 0 <= x < c and charmap[y][x] in {'+','-','|'} and levels[y][x] == -1)

def expand(y, x, put):
    if charmap[y][x] == '|' or charmap[y][x] == '+':
        if valid(y+1, x):
            levels[y+1][x] = put
        if valid(y-1, x):
            levels[y-1][x] = put
    if charmap[y][x] == '-' or charmap[y][x] == '+':
        if valid(y, x+1):
            levels[y][x+1] = put
        if valid(y, x-1):
            levels[y][x-1] = put

for _ in xrange(int(raw_input())):
    r = int(raw_input())
    c = int(raw_input())
    charmap = [list(raw_input()) for i in xrange(r)]
    levels = [[-1 for i in xrange(c)] for i in xrange(r)]
    levels[0][0] = 1
    for i in xrange(1, r*c+1):
        for y in xrange(r):
            for x in xrange(c):
                if levels[y][x] == i:
                    expand(y, x, i+1)
    print levels[r-1][c-1]
