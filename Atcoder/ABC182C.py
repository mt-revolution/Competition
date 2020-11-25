import itertools

num = list(int(input()))
num_size = len(num)

answer = -1

for k in range(num_size, 0, -1):
    for v in itertools.combinations(num, k):
        print(v)
        if sum(v) % 3 == 0:
            answer = k

print(answer)



