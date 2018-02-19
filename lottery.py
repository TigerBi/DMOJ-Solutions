out = []
for _ in xrange(int(raw_input())):
    equation = raw_input().split()
    
    while 1:
        changed = 0
        for i in xrange(len(equation)-1):
            if equation[i+1] == 'X':
                equation[i] = '(' + equation[i]
                equation[i+2] += ')'
                equation[i] = ' '.join(equation[i:i+3])
                del equation[i+2], equation[i+1]
                changed = 1
                break
        if not changed: break
        
    while len(equation) != 1:
        opened = 0
        for i in xrange(len(equation)):
            if not opened:
                equation[i] = '(' + equation[i]
                opened = 1
                continue
            if equation[i] in {'+', '-'}:
                equation[i+1] += ')'
                equation[i-1] = ' '.join(equation[i-1:i+2])
                del equation[i+1], equation[i]
                break
    out.append(''.join(equation)[1:-1])
    
print '\n\n'.join(out)
