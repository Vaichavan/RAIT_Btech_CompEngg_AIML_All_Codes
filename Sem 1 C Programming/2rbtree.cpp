void main() {
    clrscr();  // Clear the screen for Turbo C++
    RedBlackTree bst;

    int choice, value;
    while (1) {  // Changed from while (true) to while (1)
        cout << "Red-Black Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Print Tree\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "Enter the number to delete: ";
                cin >> value;
                bst.deleteNode(value);
                break;
            case 3:
                bst.printTree();
                break;
            case 4:
                cout << "Exiting the program...\n";
                getch();  // Wait for user input before closing
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }

        cout << endl;
    }
}
