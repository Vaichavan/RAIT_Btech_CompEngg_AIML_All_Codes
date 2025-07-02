def exception_handling_demo():
    try:
        num1 = int(input("Enter the first number: "))
        num2 = int(input("Enter the second number: "))
        result = num1 / num2
        print(f"Result of division: {result}")
    except ZeroDivisionError as e:
        print("Error: Division by zero is not allowed!")
        print(f"Exception: {e}")
    except ValueError as e:
        print("Error: Invalid input! Please enter a valid integer.")
        print(f"Exception: {e}")
    except Exception as e:
        print("An unexpected error occurred!")
        print(f"Exception: {e}")
    finally:
        print("End of exception handling demonstration.")

exception_handling_demo()


def raise_exception_demo(): 
    try: 
        age = int(input("Enter your age: ")) 
        if age < 18: 
            raise ValueError("Age must be 18 or above to register.") 
        print("Registration successful!") 
    except ValueError as e: 
        print(f"Raised Exception: {e}")

raise_exception_demo() 
