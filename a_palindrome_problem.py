def main():
    x = raw_input()
    for i in xrange(1,len(x)):
        if x[:i] == x[:i][::-1] and x[i:] == x[i:][::-1]: return True
    return False

print "YES" if main() else "NO"
