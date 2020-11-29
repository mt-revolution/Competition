n = int(input())

left = 1
right = 1000000000000000000

# 二分探索
while right - left > 1:
    mid = (int)((left + right)/2)

    # 条件を満たせば範囲を大きな値に絞る
    if n*(n+1) <= (n-mid+2)*(mid+n+1):
        left = mid
    # 条件を満たさなければ範囲を小さな値に絞る
    else:
        right = mid

x = left
print(n - x + 2)