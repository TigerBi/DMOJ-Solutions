#incorrect - it turns out that brackets can be placed anywhere!

operators = {'+','-','*','/'}

def evaluate(s):
    s = ''.join(s)
    for x in operators:
        s = s.replace(x, ')'+x)
    s = '((('+s
    return eval(s)

for _ in xrange(int(raw_input())):
    deck = ' '.join([raw_input() for i in xrange(4)])
    found = 0
    for i in xrange(len(deck)):
        if deck[i] == ' ':
            found += 1
            if found == 1: first = i
            elif found == 2: second = i
            elif found == 3: third = i
    max_result = 0
    for a in operators:
        clone = list(deck)
        clone[first] = a
        for b in operators:
            clone[second] = b
            for c in operators:
                clone[third] = c
                result = evaluate(clone)
                if result <= 24 and result > max_result:
                    max_result = result
                result = eval(''.join(clone))
                if result <= 24 and result > max_result:
                    max_result = result
    print max_result
