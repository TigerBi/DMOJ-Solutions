stack = []
args = raw_input().replace('^','**').split()

for item in args:
    if item in {'+','-','%','/','*','**'}:
        stack[-2] = eval(str(stack[-2])+item+str(stack[-1]))
        del stack[-1]
    else: stack.append(float(item))

print "%.1f" % (stack[0])
