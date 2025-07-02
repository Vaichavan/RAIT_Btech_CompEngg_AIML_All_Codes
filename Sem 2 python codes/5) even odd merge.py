def split_even_odd(numbers):
    even_list = [num for num in numbers if num % 2 == 0]
    odd_list = [num for num in numbers if num % 2 != 0]
    return even_list, odd_list

def merge_and_sort(list1, list2):
    merged_list = list1 + list2
    merged_list.sort()
    return merged_list

numbers = [int(x) for x in input("Enter numbers separated by space: ").split()]

even_list, odd_list = split_even_odd(numbers)
print("Even list:", even_list)
print("Odd list:", odd_list)

merged_sorted_list = merge_and_sort(even_list, odd_list)
print("Merged and sorted list:", merged_sorted_list)
