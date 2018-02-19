sets = {chr(i):[set(),[]] for i in xrange(65,91)} # ie. A:({a,b,c},[B])
used = set()

for _ in xrange(int(raw_input())):
    s,e = raw_input().split(" contains ")
    used.add(s)
    used.add(e)
    if ord(e) >= 91: sets[s][0].add(e)
    else: sets[s][1].append(e)

for _ in xrange(2):
    for s in sets:
        for cross in sets[s][1]: sets[s][0] |= sets[cross][0]

used = sorted(list(used))
for item in used:
    if ord(item) >= 91: break
    print "%s = {%s}" % (item, ','.join(sorted(list(sets[item][0]))))
