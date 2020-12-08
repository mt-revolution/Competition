import math

A, R, N = map(int, input().split())

# AR^(N-1)>10^9のとき
if math.log10(A) + (N-1) * math.log10(R) > 9:
    print("large")
# それ以外
else:
    print(A * R ** (N-1))