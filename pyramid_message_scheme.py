from sys import stdin
raw_input = lambda: stdin.readline().strip()
readint = lambda: int(stdin.readline())

tree = {}
max_len = 0

def depthSearch(branch, length):
    global max_len
    length += 1
    if tree[branch]:
        for node in tree[branch]:
            depthSearch(node, length)
    else:
        max_len = max(max_len, length)

for _ in xrange(readint()):
    max_len = 0
    length = readint()
    tokens = [raw_input() for i in xrange(length)]
    tree = {tokens[-1]:[]}
    path = [tokens[-1]]
    for name in tokens:
        if not name in tree:
            tree[name] = []
            tree[path[-1]].append(name)
            path.append(name)
        elif name == path[-2]:
            del path[-1]
    init_time = 0
    for node in tree:
        init_time += len(tree[node])*20
    depthSearch(path[0], -1)
    print init_time - (max_len*20)
