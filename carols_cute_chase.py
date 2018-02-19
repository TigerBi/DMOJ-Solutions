n,m = map(int, raw_input().split())
buf = [list(map(int, raw_input().split())) for i in xrange(m)]

def form():
    global n, buf
    out = [i for i in xrange(n+1)]
    for item in buf:
        for i in xrange(n):
            if out[i] == item[1]: out[i] = item[0]
    return out

for i in xrange(m):
    x = buf.pop(i)
    tmp = form()
    print tmp
    if tmp[1] == tmp[n]: print "YES"
    else: print "NO"
    buf.insert(i,x)
