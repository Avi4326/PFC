def swap_strings(str1, str2, n):
    return str2[:n] + str1[n:], str1[:n] + str2[n:]

str1 = input("Enter the first string: ")
str2 = input("Enter the second string: ")
n = int(input("Enter the number of characters to swap: "))

new_str1, new_str2 = swap_strings(str1, str2, n)
print("New first string:", new_str1)
print("New second string:", new_str2)
