import sqlite3
import tkinter as tk
from tkinter import messagebox, ttk

def create_db():
    with sqlite3.connect('students.db') as conn:
        conn.execute('''
        CREATE TABLE IF NOT EXISTS students (
            id INTEGER PRIMARY KEY,
            name TEXT NOT NULL,
            age INTEGER NOT NULL
        ) ''')
    messagebox.showinfo("Success", "Database created!")

def insert_student():
    name = entry_name.get()
    age = entry_age.get()

    if name and age.isdigit():
        with sqlite3.connect('students.db') as conn:
            conn.execute("INSERT INTO students (name, age) VALUES (?, ?)", (name, int(age)))
        messagebox.showinfo("Success", "Student added!")

        # Clear the input fields
        entry_name.delete(0, tk.END)
        entry_age.delete(0, tk.END)
        
        # Update the student list display
        display_students()
    else:
        messagebox.showerror("Error", "Invalid input. Please enter a valid name and age.")

def display_students():
    # Clear the existing data in the Treeview
    for row in tree.get_children():
        tree.delete(row)
    
    # Fetch data from the database and display in the Treeview
    with sqlite3.connect('students.db') as conn:
        for row in conn.execute("SELECT * FROM students"):
            tree.insert("", tk.END, values=row)

# Create the main window
root = tk.Tk()
root.title("Student Database")

# Create database button
tk.Button(root, text="Create Database", command=create_db).pack(pady=10)

# Input fields for student name and age
entry_name = tk.Entry(root)
entry_name.pack(pady=5)
entry_name.insert(0, "Name")

entry_age = tk.Entry(root)
entry_age.pack(pady=5)
entry_age.insert(0, "Age")

# Insert student button
tk.Button(root, text="Insert Student", command=insert_student).pack(pady=10)

# Display students button
tk.Button(root, text="Display Students", command=display_students).pack(pady=10)

# Treeview widget to display the list of students
tree = ttk.Treeview(root, columns=('ID', 'Name', 'Age'), show='headings')
tree.heading('ID', text='ID')
tree.heading('Name', text='Name')
tree.heading('Age', text='Age')
tree.pack(pady=10)

# Run the application
root.mainloop()
