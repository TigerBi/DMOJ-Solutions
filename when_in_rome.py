# works perfectly :)

keys = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
reversed_keys = {}
for item in keys:
    reversed_keys[keys[item]] = item
vals = [1000, 500, 100, 50, 10, 5, 1]

def toInteger(s):
    out = 0
    last = keys[s[0]]
    for char in s:
        if keys[char] > last:
            out -= last
            out += keys[char]-last
        else:
            out += keys[char]
        last = keys[char]
    return out

for i in range(int(raw_input())):
    line = raw_input().strip('=').split('+')
    total = toInteger(line[0]) + toInteger(line[1])
    if total > 1000:
        print '+'.join(line) + '=' + "CONCORDIA CUM VERITATE"
        continue
    out = ""
    index = 0
    while total > 0:
        if total - vals[index] < 0:
            index += 1
            continue
        out += reversed_keys[vals[index]]
        total -= vals[index]
    print '+'.join(line) + '=' + out.replace("DCCCC","CM").replace("LXXXX","XC").replace("VIIII","IX").replace("XXXX","XL").replace("IIII","IV").replace("CCCC","CD")
