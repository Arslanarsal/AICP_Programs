#include <iostream>
using namespace std;
// Hexagon
class Hexagon
{
    void calcArea()
    {
        cout << "Area of hexagon is: " << 1.5 * 1.732 * 9 << endl;
    }

    void calcPeri()
    {
        cout << "perimeter of hexagon is: " << 6 * 9 << endl;
    }
    void calcAngleSum()
    {
        cout << "Sum of all angles of hexagon is: " << 6 * 120 << endl;
    }

public:
    void display()
    {
        cout << endl;
        calcArea();
        calcPeri();
        calcAngleSum();
    }
};

// Square

class Square
{

    void calcAreaSquare()
    {
        cout << "Area of square is: " << (10 + 1) * 2 << endl;
    }
    void calcPeriSquare()
    {
        cout << "perimeter of square is: " << (10 + 1) * 4 << endl;
    }

public:
    void display()
    {
        cout << endl;
        calcAreaSquare();
        calcPeriSquare();
    }
};

int main()
{
    system("cls");
    string cnic = "34403-4179476-9";
    Hexagon hexa;
    Square sq;

    while (true)
    {
        cout << "\n\n\nEnter 1 to calculate area, perimeter, ans sum of angles of hexagon" << endl;
        cout << "Enter 2 to calculate area and perimeter of Square" << endl;
        cout << "Press Any other key to exit\n"
             << endl;

        char choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '1')
        {
            hexa.display();
        }
        else if (choice == '2')
        {
            sq.display();
        }
        else
        {
            break;
        }
    }

    return 0;
}