N = input()

new = ''
low = 'abcdefghijklmnopqrstuvwxyz'
cap = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

for char in raw_input():
    if char == ' ':
        new += char
        continue
    
    if char.islower():
        ind = low.index(char)
        if N > 0:
            ind -= N
            if ind < -26:
                ind = (ind * -1) % 26
                new += low[-ind]
            else:
                new += low[ind]
        else:
            ind = (ind + (-N)) % 26
            new += low[ind]
    else:
        ind = cap.index(char)
        if N > 0:
            ind -= N
            if ind < -26:
                ind = (ind * -1) % 26
                new += cap[-ind]
            else:
                new += cap[ind]
        else:
            ind = (ind + (-N)) % 26
            new += cap[ind]

print new
