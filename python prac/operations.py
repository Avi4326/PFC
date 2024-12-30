def file_operations():
    filename = input("Enter the filename: ")
    with open(filename, 'r') as f:
        lines = f.readlines()

    total_characters = sum(len(line) for line in lines)
    total_words = sum(len(line.split()) for line in lines)
    total_lines = len(lines)
    print("Total characters:", total_characters)
    print("Total words:", total_words)
    print("Total lines:", total_lines)

    char_frequency = {}
    for line in lines:
        for char in line:
            char_frequency[char] = char_frequency.get(char, 0) + 1
    print("Character frequencies:", char_frequency)

    reversed_words = [word[::-1] for line in lines for word in line.split()]
    print("Words in reverse order:", reversed_words)

    with open('File1.txt', 'w') as f1, open('File2.txt', 'w') as f2:
        for i, line in enumerate(lines):
            if i % 2 == 0:
                f1.write(line)
            else:
                f2.write(line)

file_operations()
