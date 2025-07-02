def factorial(n):
    if n <= 1:
        return 1
    else:
        return n * factorial(n - 1)

num = int(input("Enter a number to find its factorial: "))
if num < 0:
    print("Factorial is not defined for negative numbers")
else:
    print(f"The factorial of {num} is {factorial(num)}")
