y,l = map(int, raw_input().split())
ranks = [0 for i in xrange(y)]
scores = [0 for i in xrange(y)]

for _ in xrange(l):
    points = list(map(int, raw_input().split()))
    for i in xrange(y):
        scores[i] += points[i]
    tmp = sorted(list(set(scores)))[::-1]
    for i in xrange(y):
        ranks[i] = max(ranks[i],tmp.index(scores[i])+1)

best = max(scores)
for i in xrange(y):
    if scores[i] == best:
        print "Yodeller %d is the TopYodeller: score %d, worst rank %d" % (i+1,scores[i],ranks[i])
