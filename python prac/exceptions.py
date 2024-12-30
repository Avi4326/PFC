def accept_name():
    name = input("Enter your name: ")
    try:
        if any(char.isdigit() for char in name) or not name.isalpha():
            raise ValueError("Name should not contain digits or special characters")
        print("Name accepted:", name)
    except ValueError as e:
        print(e)

accept_name()
