n = int(input())

left = 1
right = 1000000000000000000

while right - left > 1:
    mid = (int)((left + right)/2)

    if n*(n+1) <= (n-mid+2)*(mid+n+1):
        left = mid
    else:
        right = mid

x = left
print(n - x + 2)