from pathlib import Path

current_directory = Path('.')
files = current_directory.iterdir()

print("Files and directories in the current directory:")
for file in files:
    print(file.name)

