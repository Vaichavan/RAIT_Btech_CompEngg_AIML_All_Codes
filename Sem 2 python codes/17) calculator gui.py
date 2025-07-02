import tkinter as tk

root = tk.Tk()
root.title("Calculator")

label_result = tk.Label(root, width=16, height=2, text="", font=("Arial", 16))
label_result.grid(row=0, column=0, columnspan=4)

expression = ""

def add(value):
    global expression
    expression += value
    label_result.config(text=expression)

def clear():
    global expression
    expression = ""
    label_result.config(text=expression)

def calculate():
    global expression
    try:
        result = eval(expression)
        result = round(result, 2)  # Format result to 2 decimal places
        label_result.config(text=result)
        expression = str(result)
    except Exception as e:
        label_result.config(text="Error")
        expression = ""

button_size = {"width": 5, "height": 2, "font": ("Arial", 14)}

button_1 = tk.Button(root, text="1", **button_size, command=lambda: add("1"))
button_1.grid(row=1, column=0)
button_2 = tk.Button(root, text="2", **button_size, command=lambda: add("2"))
button_2.grid(row=1, column=1)
button_3 = tk.Button(root, text="3", **button_size, command=lambda: add("3"))
button_3.grid(row=1, column=2)
button_multiply = tk.Button(root, text="*", **button_size, command=lambda: add("*"))
button_multiply.grid(row=1, column=3)

button_4 = tk.Button(root, text="4", **button_size, command=lambda: add("4"))
button_4.grid(row=2, column=0)
button_5 = tk.Button(root, text="5", **button_size, command=lambda: add("5"))
button_5.grid(row=2, column=1)
button_6 = tk.Button(root, text="6", **button_size, command=lambda: add("6"))
button_6.grid(row=2, column=2)
button_divide = tk.Button(root, text="/", **button_size, command=lambda: add("/"))
button_divide.grid(row=2, column=3)

button_7 = tk.Button(root, text="7", **button_size, command=lambda: add("7"))
button_7.grid(row=3, column=0)
button_8 = tk.Button(root, text="8", **button_size, command=lambda: add("8"))
button_8.grid(row=3, column=1)
button_9 = tk.Button(root, text="9", **button_size, command=lambda: add("9"))
button_9.grid(row=3, column=2)
button_plus = tk.Button(root, text="+", **button_size, command=lambda: add("+"))
button_plus.grid(row=3, column=3)

button_clear = tk.Button(root, text="C", **button_size, command=lambda: clear())
button_clear.grid(row=4, column=0)
button_0 = tk.Button(root, text="0", **button_size, command=lambda: add("0"))
button_0.grid(row=4, column=1)
button_dot = tk.Button(root, text=".", **button_size, command=lambda: add("."))
button_dot.grid(row=4, column=2)
button_minus = tk.Button(root, text="-", **button_size, command=lambda: add("-"))
button_minus.grid(row=4, column=3)

button_calculate = tk.Button(root, text="=", width=22, height=2, font=("Arial", 14), command=lambda: calculate())
button_calculate.grid(row=5, column=0, columnspan=4)

root.mainloop()
