from sys import stdin
raw_input = lambda: stdin.readline().strip()
readint = lambda: int(stdin.readline())

links = {}
pages_to_go = readint()
while pages_to_go:
    page = raw_input()
    links[page] = []
    line = raw_input()
    while line != "</HTML>":
        line = line.split()
        for item in line:
            if item.startswith("HREF="):
                item = item[6:]
                link = ""
                for char in item:
                    if char == '"':
                        break
                    link += char
                links[page].append(link)
                print "Link from %s to %s" % (page, link)
        line = raw_input()
    pages_to_go -= 1

pages_to_go = 1
inds = []
nums = []
for i in sorted(links):
    for item in links[i]:
        nums.append(item)
        inds.append(pages_to_go)
    pages_to_go += 1

print inds, nums

#while 1:
#    start = raw_input()
#    if start == "The End":
#        break
#    ;
