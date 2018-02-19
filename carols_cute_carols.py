raw_input()
arr = list(map(int, raw_input().split()))
target = sorted(arr)[::-1]
swaps = 0
x = len(arr)-1

while arr != target:
    for i in range(x):
        if arr[i] < arr[i+1]:
            tmp = arr[i]
            arr[i] = arr[i+1]
            arr[i+1] = tmp
            swaps += 1

print swaps
