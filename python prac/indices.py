def find_occurrences(str1, str2):
    indices = []
    start = 0
    while start < len(str1):
        start = str1.find(str2, start)
        if start == -1:
            break
        indices.append(start)
        start += 1
    return indices if indices else -1

str1 = input("Enter the first string: ")
str2 = input("Enter the second string: ")

print(find_occurrences(str1, str2))
