def count_file_details(file_path):
    with open(file_path, 'r') as fp:
        lines = 0
        words = 0
        characters = 0
        for line in fp:
            lines += 1
            words += len(line.split())
            characters += len(line)
    
    print('Total Number of lines:', lines)
    print('Total Number of words:', words)
    print('Total Number of characters:', characters)

count_file_details('input.txt')
