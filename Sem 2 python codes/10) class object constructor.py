class Student:
    def __init__(self, name, roll_no, marks):
        self.name = name
        self.roll_no = roll_no
        self.marks = marks

    def display_info(self):
        print(f"Name: {self.name}")
        print(f"Roll Number: {self.roll_no}")
        print(f"Marks: {self.marks}")
        print(f"Total Marks: {sum(self.marks)}")
        print("-" * 30)

student1 = Student("Vaibhav", 101, [85, 90, 88])
student2 = Student("OM", 102, [78, 82, 80])

print("Displaying Student Information:")
student1.display_info()
student2.display_info()
