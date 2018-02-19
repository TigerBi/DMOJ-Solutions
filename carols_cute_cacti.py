raw_input()
arr = list(map(int, raw_input().split()))
best = None
best_count = 0
for item in sorted(list(set(arr))):
    if arr.count(item) > best_count:
        best = item
        best_count = arr.count(item)
print best
