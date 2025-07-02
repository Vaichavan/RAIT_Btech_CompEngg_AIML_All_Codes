def copy_file_content(source_file, destination_file):
    try:
        with open(source_file, 'r') as src:
            content = src.read()
        with open(destination_file, 'w') as dest:
            dest.write(content)
        print(f"Content copied from {source_file} to {destination_file} successfully!")
    except FileNotFoundError:
        print(f"Error: The file {source_file} does not exist.")
    except Exception as e:
        print(f"An error occurred: {e}")

copy_file_content('input.txt', 'output.txt')
