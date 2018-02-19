# Solution to CCC <year> Spreadsheet 100%AC

sheet = [raw_input().split() for i in range(10)]

def isNumber(x):
    try:
        int(x)
    except ValueError:
        return 0
    return 1

while 1:
    changed = 0

    for y in range(10):
        for x in range(9):
            if changed:
                break
            cell = sheet[y][x]
            if not isNumber(cell):
                commands = cell.split('+')
                putcell = []
                for command in commands:
                    row = ord(command[0])-65
                    column = int(command[1:])-1
                    if isNumber(sheet[row][column]):
                        putcell.append(int(sheet[row][column]))
                    else:
                        break
                if len(putcell) != len(commands):
                    continue
                sheet[y][x] = sum(putcell)
                changed = 1
        if changed:
            break

    if not changed:
        break

for y in range(10):
    for x in range(9):
        if not isNumber(sheet[y][x]):
            sheet[y][x] = '*'

for line in sheet:
    build = ''
    for item in line:
        build += str(item)+' '
    print(build.rstrip())
