def find_frequency(s, char):
    return s.count(char)

def replace_char(s, old_char, new_char):
    return s.replace(old_char, new_char)

def remove_first_occurrence(s, char):
    return s.replace(char, '', 1)

def remove_all_occurrences(s, char):
    return s.replace(char, '')

s = input("Enter a string: ")
char = input("Enter the character to find its frequency: ")
print(f"Frequency of '{char}' in the string: {find_frequency(s, char)}")

old_char = input("Enter the character to replace: ")
new_char = input("Enter the new character: ")
print(f"String after replacement: {replace_char(s, old_char, new_char)}")

char_to_remove = input("Enter the character to remove the first occurrence: ")
print(f"String after removing the first occurrence of '{char_to_remove}': {remove_first_occurrence(s, char_to_remove)}")

char_to_remove_all = input("Enter the character to remove all occurrences: ")
print(f"String after removing all occurrences of '{char_to_remove_all}': {remove_all_occurrences(s, char_to_remove_all)}")
