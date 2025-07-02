numbers = [10, 20, 30, 40, 50, 60]

new_value = int(input("Enter the new value for the first element: "))
numbers[0] = new_value

middle_index = len(numbers) // 2
if len(numbers) % 2 == 0:
    middle_index -= 1
numbers.pop(middle_index)

print("Updated list:", numbers)

print("Max element:", max(numbers))
print("Min element:", min(numbers))
