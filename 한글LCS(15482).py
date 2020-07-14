s1 = str(input())
s2 = str(input())

s1 = "*" + s1
s2 = "*" + s2

table = [[0 for i in range(len(s2))] for j in range(len(s1))]

for r in range(1, len(s1)):
    for c in range(1, len(s2)):
        value = s1[r] == s2[c] and 1 or 0
        table[r][c] = max({table[r-1][c], table[r][c-1], table[r-1][c-1] + value})

print(table[len(s1)-1][len(s2)-1])