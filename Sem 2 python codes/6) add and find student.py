list = ["om","rahul","ram"]

n = int(input("Enter the number of names to add: "))
names = [input(f"Enter name {i + 1}: ") for i in range(n)]
list.extend(names)

print("Updated list:", list)

if "Python" in list:
    print("'Python' is present in the list.")
else:
    print("'Python' is not present in the list.")
