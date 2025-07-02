def is_palindrome(value):
    str_value = str(value)
    return str_value == str_value[::-1]

num = int(input("Enter a number to check if it's a palindrome: "))
if is_palindrome(num):
    print(f"{num} is a palindrome")
else:
    print(f"{num} is not a palindrome")

string = input("Enter a string to check if it's a palindrome: ")
if is_palindrome(string):
    print(f'"{string}" is a palindrome')
else:
    print(f'"{string}" is not a palindrome')
