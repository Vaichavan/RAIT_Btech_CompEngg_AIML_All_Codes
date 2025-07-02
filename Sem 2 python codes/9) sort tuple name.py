def add_students():
    n = int(input("Enter number of students: "))
    students = []
    for i in range(n):
        roll_no = input(f"Enter roll number for student {i + 1}: ")
        name = input(f"Enter name for student {i + 1}: ")
        marks = [int(input(f"Enter marks for subject {j + 1}: ")) for j in range(3)]
        students.append((roll_no, name, tuple(marks)))
    return students

def display_sorted_students(students):
    sorted_students = sorted(students, key=lambda student: student[1])  # Sort by name
    for roll_no, name, marks in sorted_students:
        print(f"Roll Number: {roll_no}, Name: {name}, Marks: {marks}")

students = []
while True:
    print("\nMenu:")
    print("1. Add student data")
    print("2. Display sorted students by name")
    print("3. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        students = add_students()
    elif choice == 2:
        display_sorted_students(students)
    elif choice == 3:
        break
    else:
        print("Invalid choice!")
