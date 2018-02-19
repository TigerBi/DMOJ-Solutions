raw_input()

arr = list(map(int, raw_input().split()))
tmp = [0 for i in xrange(len(arr))]
length = len(arr)
mod = 10**9+7

for _ in xrange(int(raw_input())):
    s = 0
    for i in xrange(length):
        s += arr[i]
        tmp[i] = s
    arr = tmp

print ' '.join([str(item%mod) for item in arr])
