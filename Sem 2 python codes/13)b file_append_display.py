def append_and_display_file(file_name, data_to_append):
    try:
        with open(file_name, 'a') as file:
            file.write(data_to_append + '\n')
        print(f"Data appended successfully to {file_name}.")

        print(f"Displaying the content of {file_name}:")
        with open(file_name, 'r') as file:
            content = file.read()
            print(content)
    except FileNotFoundError:
        print(f"Error: The file {file_name} does not exist.")
    except Exception as e:
        print(f"An error occurred: {e}")

append_and_display_file('append_file.txt', 'This is the appended data.')
