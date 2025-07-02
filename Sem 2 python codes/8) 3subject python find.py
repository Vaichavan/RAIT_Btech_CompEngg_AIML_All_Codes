def add_student_data():
    n = int(input("Enter the number of students: "))
    students = []
    for i in range(n):
        roll_no = input(f"Enter roll number for student {i + 1}: ")
        name = input(f"Enter name for student {i + 1}: ")
        marks = [int(input(f"Enter marks for subject {j + 1}: ")) for j in range(3)]
        students.append((roll_no, name, tuple(marks)))
    return students

def display_student_by_name(students, search_name="Python"):
    for roll_no, name, marks in students:
        if name == search_name:
            print(f"Roll Number: {roll_no}, Marks: {marks}")
            return
    print(f"Student with name '{search_name}' not found.")

students = []
while True:
    print("\nMenu:")
    print("1. Add and show student data")
    print("2. Display student roll number and marks whose name is 'Python'")
    print("3. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        students = add_student_data()
        for student in students:
            print(student)
    elif choice == 2:
        display_student_by_name(students)
    elif choice == 3:
        break
    else:
        print("Invalid choice!")
