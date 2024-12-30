def print_digit_name(n):
    digit_names = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
    return digit_names[n]

char = input("Enter a character: ")

if char.isalpha():
    print(f"{char} is a letter.")
    if char.isupper():
        print("It is uppercase.")
    else:
        print("It is lowercase.")
elif char.isdigit():
    print(f"{char} is a numeric digit.")
    print(f"Its name in text is {print_digit_name(int(char))}.")
else:
    print(f"{char} is a special character.")
