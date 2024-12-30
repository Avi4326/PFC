t1 = (1, 2, 5, 7, 9, 2, 4, 6, 8, 10)
t2 = (11, 13, 15)

half = len(t1) // 2
print(t1[:half])
print(t1[half:])

even_tuple = tuple(x for x in t1 if x % 2 == 0)
print(even_tuple)

concatenated_tuple = t1 + t2
print(concatenated_tuple)

print("Max:", max(t1))
print("Min:", min(t1))
