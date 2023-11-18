#include <iostream>
using namespace std;

// Define the cost units for each slab
const int Units[3][3] = {
    {55, 65, 75},
    {120, 150, 170},
    {210, 230, 240}};

// Calculate and display the bill for Slab 1
void costSlab1()
{
    cout << "\nBill for Slab 1:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Unit " << (i + 1) << ": " << 10 * Units[0][i] << "   ";
    }
    cout << endl;
}

// Calculate and display the bill for Slab 2
void costSlab2()
{
    cout << "\nBill for Slab 2:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Unit " << (i + 1) << ": " << 15 * Units[1][i] << "   ";
    }
    cout << endl;
}

// Calculate and display the bill for Slab 3
void costSlab3()
{
    cout << "\nBill for Slab 3:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Unit " << (i + 1) << ": " << 20 * Units[2][i] << "   ";
    }
    cout << endl;
}

int main()
{
    system("cls"); // Clear the console screen (Windows specific)

    while (true)
    {
        int choice;

        cout << "\n\nMy Student ID is 23Y520011\n";
        cout << "Press 1 to display the bill for Slab 1 and Slab 2.\n";
        cout << "Press 2 to display the bill for Slab 3.\n";
        cout << "Press any other key to exit.\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            costSlab1();
            costSlab2();
        }
        else if (choice == 2)
        {
            costSlab3();
        }
        else
        {
            return 0; // Exit the program if any other key is pressed
        }
    }
    return 0;
}
