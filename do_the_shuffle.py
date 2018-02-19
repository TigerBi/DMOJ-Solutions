arr = list("ABCDE")
while 1:
    b = int(raw_input())
    n = int(raw_input())
    if b == 4: break
    for _ in xrange(n):
        if b == 1: arr.insert(4, arr.pop(0))
        elif b == 2: arr.insert(0, arr.pop(-1))
        elif b == 3: arr.insert(0, arr.pop(1))

print ' '.join(arr)
