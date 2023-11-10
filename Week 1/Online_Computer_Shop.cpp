#include <iostream>
#include <vector>
using namespace std;

// Arrays to store item information
string item_code[] = {"A1", "A2", "B1", "B2", "B3", "C1", "C2", "C3", "D1", "D2", "E1", "E2", "E3", "F1", "F2", "G1", "G2"};
string description[] = {"Compact", "Tower", "8 GB", "16 GB", "32 GB", "1 TB HDD", "2 TB HDD", "4 TB HDD", "240 GB SSD", "480 GB SSD", "1 TB HDD", "2 TB HDD", "4 TB HDD", "DVD/Blu-Ray Player", "DVD/Blu-Ray Re-writer", "Standard Version", "Professional Version"};
double price[] = {75.00, 150.00, 79.99, 149.99, 299.99, 49.99, 89.99, 129.99, 59.99, 119.99, 49.99, 89.99, 129.99, 50.00, 100.00, 100.00, 175.00};

// Function to calculate the total price of the main items
double calculateMainItemsPrice(string cases, string ram, string disk)
{
    double total_price = 200;
    for (int i = 0; i < 17; i++)
    {
        if (item_code[i] == cases)
        {
            total_price += price[i];
        }
        else if (item_code[i] == ram)
        {
            total_price += price[i];
        }
        else if (item_code[i] == disk)
        {
            total_price += price[i];
        }
    }
    return total_price;
}

// Function to display the main menu
void displayMainMenu()
{
    cout << "Category\t\tItem code\tDescription\t\t\tPrice ($)" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    // Case
    cout << "Case\t\t\tA1\t\tCompact\t\t\t\t75.00" << endl;
    cout << "Case\t\t\tA2\t\tTower\t\t\t\t150.00" << endl;

    // RAM
    cout << "RAM\t\t\tB1\t\t8 GB\t\t\t\t79.99" << endl;
    cout << "RAM\t\t\tB2\t\t16 GB\t\t\t\t149.99" << endl;
    cout << "RAM\t\t\tB3\t\t32 GB\t\t\t\t299.99" << endl;

    // Main Hard Disk Drive
    cout << "Main Hard Disk Drive\tC1\t\t1 TB HDD\t\t\t49.99" << endl;
    cout << "Main Hard Disk Drive\tC2\t\t2 TB HDD\t\t\t89.99" << endl;
    cout << "Main Hard Disk Drive\tC3\t\t4 TB HDD\t\t\t129.99" << endl;

    // Solid State Drive
    cout << "Solid State Drive\tD1\t\t240 GB SSD\t\t\t59.99" << endl;
    cout << "Solid State Drive\tD2\t\t480 GB SSD\t\t\t119.99" << endl;

    // Second Hard Disk Drive
    cout << "Second Hard Disk Drive\tE1\t\t1 TB HDD\t\t\t49.99" << endl;
    cout << "Second Hard Disk Drive\tE2\t\t2 TB HDD\t\t\t89.99" << endl;
    cout << "Second Hard Disk Drive\tE3\t\t4 TB HDD\t\t\t129.99" << endl;

    // Optical Drive
    cout << "Optical Drive\t\tF1\t\tDVD/Blu-Ray Player\t\t50.00" << endl;
    cout << "Optical Drive\t\tF2\t\tDVD/Blu-Ray Re-writer\t\t100.00" << endl;

    // Operating System
    cout << "Operating System\tG1\t\tStandard Version\t\t100.00" << endl;
    cout << "Operating System\tG2\t\tProfessional Version\t\t175.00" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
}

// Function for Task 1 - Choosing main items
double chooseMainItems(vector<string> &items)
{
    string cases;
    string ram;
    string drive;

    cout << "Choose item code of one case   : ";
    cin >> cases;
    while (cases != "A1" && cases != "A2")
    {
        cout << "\nERROR! Please enter the case item code from above menu" << endl;
        cout << "Choose item code of one case: ";
        cin >> cases;
    }
    items.push_back(cases);

    cout << "Choose item code of one RAM    : ";
    cin >> ram;
    while (ram != "B1" && ram != "B2" && ram != "B3")
    {
        cout << "\nERROR! Please enter the ram item code from above menu" << endl;
        cout << "Choose item code of one RAM: ";
        cin >> ram;
    }
    items.push_back(ram);

    cout << "Choose one Main Hard Disk Drive: ";
    cin >> drive;
    while (drive != "C1" && drive != "C2" && drive != "C3")
    {
        cout << "\nERROR! Please enter the drive item code from above menu" << endl;
        cout << "Choose one Main Hard Disk Drive: ";

        cin >> drive;
    }
    items.push_back(drive);
    double total_price = calculateMainItemsPrice(cases, ram, drive);
    return total_price;
}

// Function to display chosen items and calculate discounts
void displayChosenItem(vector<string> item, double total)
{
    cout << "\nItems Selected\n";
    cout << "Item code\tDescription\t\t\tPrice ($)" << endl;
    cout << "----------------------------------------------------------" << endl;
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < item.size(); j++)
        {
            if (item[j] == item_code[i])
            {
                // Adjust the spacing based on the length of the description for better alignment
                if (item_code[i] == "A1" || item_code[i] == "A2" || item_code[i] == "B1" || item_code[i] == "B2" || item_code[i] == "B3")
                {
                    cout << item_code[i] << "\t\t" << description[i] << "\t\t\t\t" << price[i] << endl;
                }
                else if (item_code[i] == "C1" || item_code[i] == "C2" || item_code[i] == "C3" || item_code[i] == "D1" || item_code[i] == "D2" || item_code[i] == "E1" || item_code[i] == "E2" || item_code[i] == "E3")
                {
                    cout << item_code[i] << "\t\t" << description[i] << "\t\t\t" << price[i] << endl;
                }
                else
                {
                    cout << item_code[i] << "\t\t" << description[i] << "\t\t" << price[i] << endl;
                }
            }
        }
    }
    cout << "----------------------------------------------------------" << endl;
    cout << "The total price of computer is\t\t\t" << total << "\n";

    if (item.size() == 4)
    {
        cout << "Discount\t\t\t\t\t"
             << "5%" << endl;
        cout << "Final price after a 5% discount is\t\t" << total - total * 0.05 << "\n\n";
    }
    else if (item.size() > 4)
    {
        cout << "Discount\t\t\t\t\t"
             << "10%" << endl;
        cout << "Final price after a 10% discount is\t\t" << total - total * 0.1 << "\n\n";
    }
}

// Function to return an item price
double addItemToCart(string code, vector<string> &items)
{
    for (int i = 0; i < 17; i++)
    {
        if (item_code[i] == code)
        {
            return price[i];
        }
    }
}

int main()
{
    system("cls");
    cout << "\n\n                -------------------------------------------------------------" << endl;
    cout << "                |                                                           |" << endl;
    cout << "                |          Welcome To Online Computer Shop                  |" << endl;
    cout << "                |                                                           |" << endl;
    cout << "                -------------------------------------------------------------"
         << "\n\n\n";

    displayMainMenu();
    vector<string> items;

    // TASK1

    double total_price = chooseMainItems(items);
    displayChosenItem(items, total_price);

    while (true)
    {
        char choice;
        cout << "\n\nDo you want to buy any items from other categories? (Y/N): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
        {
            break;
        }
        else if (choice == 'y' || choice == 'Y')
        {
            system("cls");
            displayMainMenu();

            string code;
            cout << "Enter item code from above menu: ";
            cin >> code;
            while (code != "D1" && code != "D2" && code != "E1" && code != "E2" && code != "E3" && code != "F1" && code != "F2" && code != "G1" && code != "G2")
            {
                cout << "\nERROR! Please enter the item code from above menu" << endl;
                cout << "Choose item code from above menu: ";
                cin >> code;
            }
            items.push_back(code);
            total_price += addItemToCart(code, items);
            displayChosenItem(items, total_price);
        }
        else
        {
            cout << "\nERROR! Please enter (Y or N)"
                 << "\n";
        }
    }
    system("cls");
    cout << "\n\n                -------------------------------------------------------------" << endl;
    cout << "                |                                                           |" << endl;
    cout << "                |          Thank you for using Online Computer Shop         |" << endl;
    cout << "                |                                                           |" << endl;
    cout << "                -------------------------------------------------------------"
         << "\n\n";
    displayChosenItem(items, total_price);
    return 0;
}
