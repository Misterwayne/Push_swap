t = (19,42,21)
l = len(t)
p = 0

res = "the " + str(len(t)) + " numbers are : "
for i in t:
    res += str(i)
    p += 1
    if len(t) > p:
        res += ", "
print(res)