class Parent:
    def greet(self):
        print("Hello from the Parent class!")

class Child(Parent):
    def greet(self):  
        print("Hello from the Child class!")

class Calculator:
    def add(self, a=None, b=None, c=None):  
        if a is not None and b is not None and c is not None:
            return a + b + c
        elif a is not None and b is not None:
            return a + b
        elif a is not None:
            return a
        else:
            return 0

parent = Parent()
child = Child()
print("\nMethod Overriding Example:")
parent.greet()
child.greet()

calc = Calculator()
print("\nMethod Overloading Example:")
print("Sum with 2 arguments:", calc.add(10, 20))
print("Sum with 3 arguments:", calc.add(10, 20, 30))
