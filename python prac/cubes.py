def cubes_with_loop(lst):
    result = []
    for x in lst:
        if isinstance(x, int) and x % 2 == 0:
            result.append(x ** 3)
    return result

def cubes_with_comprehension(lst):
    return [x ** 3 for x in lst if isinstance(x, int) and x % 2 == 0]

lst = eval(input("Enter a list of elements: "))
print("Using 'for' loop:", cubes_with_loop(lst))
print("Using list comprehension:", cubes_with_comprehension(lst))
