l,s = map(float, raw_input().split())

a = b = c = d = e = f = _f = 0

for i in xrange(int(l)):
    x = abs(int(raw_input()))
    if x > 200:
        f = max(_f,f)
        _f = 0
        e += 1
        continue
    elif x > 150: d += 1
    elif x > 100: c += 1
    elif x > 50: b += 1
    else: a += 1
    _f += 1

f = max(_f,f)
print "%.1f" % (((a*1.5)+b+c+(d*0.5)-e+(f*0.5))-s)
