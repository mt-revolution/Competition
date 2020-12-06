import math

# 最小公倍数
def lcm(x, y):
    return (x * y) // math.gcd(x, y)

N = int(input())
answer = 1

for i in range(2, N+1):
    answer = lcm(answer, i)

print(answer + 1)