p,s = map(int, __import__("sys").stdin.readline().split())
if p%s == 0: print "yes %d" % (p/s)
else:
    add = 1
    while p%(s+add) != 0: add += 1
    print "no %d" % add
