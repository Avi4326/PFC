a = float(input("Enter coefficient a: "))
b = float(input("Enter coefficient b: "))
c = float(input("Enter coefficient c: "))

d = b**2 - 4*a*c

if d >= 0:
    root1 = (-b + d**0.5) / (2*a)
    root2 = (-b - d**0.5) / (2*a)
else:
    root1 = (-b / (2*a)) + ((-d)**0.5 / (2*a)) * 1j
    root2 = (-b / (2*a)) - ((-d)**0.5 / (2*a)) * 1j

print("Roots are:", root1, "and", root2)
