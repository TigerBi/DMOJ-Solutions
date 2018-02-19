def getRhyme(x):
    x = ''.join(x.split()[-1])
    for i in xrange(len(x)-1,-1,-1):
        if x[i] in {'a','e','i','o','u'}: return x[i:]
    return x

for i in xrange(int(raw_input())):
    ends = [getRhyme(raw_input().lower()) for i in xrange(4)]
    if ends[0] == ends[1] == ends[2] == ends[3]: print "perfect"
    elif ends[0] == ends[1] and ends[2] == ends[3]: print "even"
    elif ends[0] == ends[2] and ends[1] == ends[3]: print "cross"
    elif ends[0] == ends[3] and ends[1] == ends[2]: print "shell"
    else: print "free"
