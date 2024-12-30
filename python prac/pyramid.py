def pyramid(n):
    for i in range(1, n+1):
        print(' ' * (n - i) + '*' * (2 * i - 1))

def reverse_pyramid(n):
    for i in range(n, 0, -1):
        print(' ' * (n - i) + '*' * (2 * i - 1))

n = int(input("Enter the number of rows: "))

print("Pyramid:")
pyramid(n)

print("Reverse Pyramid:")
reverse_pyramid(n)
