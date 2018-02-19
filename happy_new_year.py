h, m, s = raw_input().split()
h, m, s = int(h), int(m), int(s)

total = (h*3600 + m*60 + s) % 43200

diff = (43200 - total) % 43200

_h = diff / 3600
_m = (diff-3600*_h) / 60
_s = diff % 60

def pad(i):
    return '0'*(2-len(str(i))) + str(i)

print pad(_h)+':'+pad(_m)+':'+pad(_s)
