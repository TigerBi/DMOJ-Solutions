n = int(raw_input())
x = int(round(n/2))
medians = [sorted(list(map(int, raw_input().split())))[x] for i in xrange(n)]
print medians[x]
