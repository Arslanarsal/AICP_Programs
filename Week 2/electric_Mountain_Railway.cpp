#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

const int price = 25;
int calculate_price(int num);

struct train
{
    int total_price = 0;

    int jour1_price = 0;
    int jour2_price = 0;
    int jour3_price = 0;
    int jour4_price = 0;

    int train1_up = 480;
    int train2_up = 480;
    int train3_up = 480;
    int train4_up = 480;
    int train1_down = 480;
    int train2_down = 480;
    int train3_down = 480;
    int train4_down = 640;
};

int Ticket_Purchase_Down(train &t);
int Ticket_Purchase_Up(train &t);

void screenDisplay(const train &t)
{
    system("cls");
    cout << "\n\n                -------------------------------------------------------------" << endl;
    cout << "                |                                                           |" << endl;
    cout << "                |           Train Journeys - Start of the Day               |" << endl;
    cout << "                |                                                           |" << endl;
    cout << "                -------------------------------------------------------------"
         << "\n\n\n";

    cout << "\n\t \n";
    // Task 1 - Start of the day
    cout << "Train Schedule                      (Up)                    (Down)\n";
    cout << "----------------------------------\n";
    cout << "Journey 1. (09:00 - 10:00) " << ((t.train1_up == 0) ? "close" : to_string(t.train1_up) + " tickets available") << " | " << ((t.train1_down == 0) ? "close" : to_string(t.train1_down) + " tickets available") << endl;
    cout << "Journey 2. (11:00 - 12:00) " << ((t.train2_up == 0) ? "close" : to_string(t.train2_up) + " tickets available") << " | " << ((t.train2_down == 0) ? "close" : to_string(t.train2_down) + " tickets available") << endl;
    cout << "Journey 3. (13:00 - 14:00) " << ((t.train3_up == 0) ? "close" : to_string(t.train3_up) + " tickets available") << " | " << ((t.train3_down == 0) ? "close" : to_string(t.train3_down) + " tickets available") << endl;
    cout << "Journey 4. (15:00 - 16:00) " << ((t.train4_up == 0) ? "close" : to_string(t.train4_up) + " tickets available") << " | " << ((t.train4_down == 0) ? "close" : to_string(t.train4_down) + " tickets available") << endl;
}

void Ticket_Purchase(train &t)
{
    int num1 = Ticket_Purchase_Up(t);
    cout << "You have booked " << num1 << " seats for the journey." << endl;
}

void displayPassengerStats(const train &t)
{
    int n1 = (480 - t.train1_up) + (480 - t.train1_down);
    int n2 = (480 - t.train2_up) + (480 - t.train2_down);
    int n3 = (480 - t.train3_up) + (480 - t.train3_down);
    int n4 = (480 - t.train4_up) + (640 - t.train4_down);

    cout << "\n\nPassenger Statistics:\n";
    cout << "----------------------------------\n";
    cout << "Journey 1. Passengers: " << n1 << " | Money: $" << t.jour1_price << endl;
    cout << "Journey 2. Passengers: " << n2 << " | Money: $" << t.jour2_price << endl;
    cout << "Journey 3. Passengers: " << n3 << " | Money: $" << t.jour3_price << endl;
    cout << "Journey 4. Passengers: " << n4 << " | Money: $" << t.jour4_price << endl;

    int total_passengers = (480 - t.train1_up) + (480 - t.train2_up) + (480 - t.train3_up) + (480 - t.train4_up) + (640 - t.train4_down);
    int total_price = t.jour1_price + t.jour2_price + t.jour3_price + t.jour4_price;
    cout << "\nTotal Passengers: " << total_passengers << " | Total Money: $" << total_price << endl;

    // Find and display the journey with the most passengers
    int max_passengers = max(n1, max(n2, max(n3, n4)));
    int max_passengers_journey = 0;

    if (max_passengers == n1)
        max_passengers_journey = 1;
    else if (max_passengers == n2)
        max_passengers_journey = 2;
    else if (max_passengers == n3)
        max_passengers_journey = 3;
    else if (max_passengers == n4)
        max_passengers_journey = 4;

    cout << "Journey with the most passengers: Journey " << max_passengers_journey << " with " << max_passengers << " passengers.\n";
}

int main()
{
    char chose;
    train myTrain;

    while (true)
    {
        screenDisplay(myTrain);
        cout << "\n\nPress A: Enter for Booking\n";
        cout << "Press B: Display Statistics and Exit\n\n";
        cout << "Enter Your Choice: ";
        cin >> chose;

        if (chose == 'A' || chose == 'a')
        {
            system("cls");
            Ticket_Purchase(myTrain);
        }
        else if (chose == 'B' || chose == 'b')
        {
            displayPassengerStats(myTrain);
            break;
        }

        cout << "Invalid Choice! Try Again.\n"
             << endl;
    }
    while (1)
    {
    }

    return 0;
}

void displayUpSeats(const train &t)
{
    cout << "Train Schedule (Up)\n";
    cout << "----------------------------------\n";
    cout << "Journey 1. (09:00) " << ((t.train1_up == 0) ? "close" : to_string(t.train1_up) + " tickets available") << endl;
    cout << "Journey 2. (11:00) " << ((t.train2_up == 0) ? "close" : to_string(t.train2_up) + " tickets available") << endl;
    cout << "Journey 3. (13:00) " << ((t.train3_up == 0) ? "close" : to_string(t.train3_up) + " tickets available") << endl;
    cout << "Journey 4. (15:00) " << ((t.train4_up == 0) ? "close" : to_string(t.train4_up) + " tickets available") << endl;
}

void displayDownSeats(const train &t)
{
    cout << "Train Schedule (Down)\n";
    cout << "----------------------------------\n";
    cout << "Journey 1. (10:00) " << ((t.train1_down == 0) ? "close" : to_string(t.train1_down) + " tickets available") << endl;
    cout << "Journey 2. (12:00) " << ((t.train2_down == 0) ? "close" : to_string(t.train2_down) + " tickets available") << endl;
    cout << "Journey 3. (14:00) " << ((t.train3_down == 0) ? "close" : to_string(t.train3_down) + " tickets available") << endl;
    cout << "Journey 4. (16:00) " << ((t.train4_down == 0) ? "close" : to_string(t.train4_down) + " tickets available") << endl;
}
// Function to handle the ticket purchase for the "up" journeys
// This function takes user input for the number of passengers and the selected journey,
// then deducts the booked seats and updates the journey prices accordingly.
// It also displays the available seats for both "up" and "down" journeys.
int Ticket_Purchase_Up(train &t)
{
    // Get the number of passengers from the user
    int num = 0;
    displayUpSeats(t);
    cout << "\nEnter the number of passengers (1-80): ";
    cin >> num;

    // Validate the number of passengers
    if (num < 1 || num > 80)
    {
        cout << "Invalid number of passengers. Please enter a number between 1 and 80.\n";
        return Ticket_Purchase_Up(t); // Recursive call if the input is invalid
    }

    // Get the selected journey from the user
    int journey = 0;
    cout << "Which up journey would you like to book? Enter 1, 2, 3, or 4: ";
    while (journey < 1 || journey > 4)
    {
        cin >> journey;
        if (journey >= 1 && journey <= 4)
        {
            break;
        }
        cout << "Error: Enter the journey number between 1 and 4: ";
    }

    // Calculate the ticket price based on the number of passengers
    int price = calculate_price(num);

    // Deduct the number of booked seats based on the selected up journey
    if (journey == 1)
    {
        // Check if there are enough available seats
        if (num > t.train1_up)
        {
            cout << "Only " << t.train1_up << " seats available for this journey. Enter a valid number of passengers.\n";
            cout << "Enter in any other journey.\n\n";
            return Ticket_Purchase_Up(t); // Recursive call if not enough seats available
        }
        // Check if the train is full
        else if (t.train1_up == 0)
        {
            cout << "This train is full. Please select another train.\n\n";
            return Ticket_Purchase_Up(t); // Recursive call if the train is full
        }
        // Deduct the booked seats and update the journey price
        t.train1_up -= num;
        t.jour1_price += price;
    }
    else if (journey == 2)
    {
        // Similar logic for journey 2
        if (num > t.train2_up)
        {
            cout << "Only " << t.train2_up << " seats available for this journey. Enter a valid number of passengers.\n";
            cout << "Enter in any other journey.\n\n";
            return Ticket_Purchase_Up(t);
        }
        else if (t.train2_up == 0)
        {
            cout << "This train is full. Please select another train.\n\n";
            return Ticket_Purchase_Up(t);
        }
        t.train2_up -= num;
        t.jour2_price += price;
    }
    else if (journey == 3)
    {
        // Similar logic for journey 3
        if (num > t.train3_up)
        {
            cout << "Only " << t.train3_up << " seats available for this journey. Enter a valid number of passengers.\n";
            cout << "Enter in any other journey.\n\n";
            return Ticket_Purchase_Up(t);
        }
        else if (t.train3_up == 0)
        {
            cout << "This train is full. Please select another train.\n\n";
            return Ticket_Purchase_Up(t);
        }
        t.train3_up -= num;
        t.jour3_price += price;
    }
    else
    {
        // Similar logic for journey 4
        if (num > t.train4_up)
        {
            cout << "Only " << t.train4_up << " seats available for this journey. Enter a valid number of passengers.\n";
            cout << "Enter in any other journey.\n\n";
            return Ticket_Purchase_Up(t);
        }
        else if (t.train4_up == 0)
        {
            cout << "This train is full. Please select another train.\n\n";
            return Ticket_Purchase_Up(t);
        }
        t.train4_up -= num;
        t.jour4_price += price;
    }

    // Display the available seats for "down" journeys
    displayDownSeats(t);

    // Get the selected "down" journey from the user
    journey = 0;
    cout << "Which down journey would you like to book? Enter 1, 2, 3, or 4: ";
    while (journey < 1 || journey > 4)
    {
        cin >> journey;
        if (journey >= 1 && journey <= 4)
        {
            break;
        }
        cout << "Error: Enter the journey number between 1 and 4: ";
    }

    // Deduct the number of booked seats based on the selected down journey
    if (journey == 1)
    {
        // Similar logic for down journey 1
        if (num > t.train1_down)
        {
            cout << "Only " << t.train1_down << " seats available for this journey. Enter a valid number of passengers.\n";
            cout << "Enter in any other journey.\n\n";
            return Ticket_Purchase_Up(t);
        }
        else if (t.train1_down == 0)
        {
            cout << "This train is full. Please select another train.\n\n";
            return Ticket_Purchase_Up(t);
        }
        t.train1_down -= num;
        t.jour1_price += price;
    }
    else if (journey == 2)
    {
        // Similar logic for down journey 2
        if (num > t.train2_down)
        {
            cout << "Only " << t.train2_down << " seats available for this journey. Enter a valid number of passengers.\n";
            cout << "Enter in any other journey.\n\n";
            return Ticket_Purchase_Up(t);
        }
        else if (t.train2_down == 0)
        {
            cout << "This train is full. Please select another train.\n\n";
            return Ticket_Purchase_Up(t);
        }
        t.train2_down -= num;
        t.jour2_price += price;
    }
    else if (journey == 3)
    {
        // Similar logic for down journey 3
        if (num > t.train3_down)
        {
            cout << "Only " << t.train3_down << " seats available for this journey. Enter a valid number of passengers.\n";
            cout << "Enter in any other journey.\n\n";
            return Ticket_Purchase_Up(t);
        }
        else if (t.train3_down == 0)
        {
            cout << "This train is full. Please select another train.\n\n";
            return Ticket_Purchase_Up(t);
        }
        t.train3_down -= num;
        t.jour3_price += price;
    }
    else
    {
        // Similar logic for down journey 4
        if (num > t.train4_down)
        {
            cout << "Only " << t.train4_down << " seats available for this journey. Enter a valid number of passengers.\n";
            cout << "Enter in any other journey.\n\n";
            return Ticket_Purchase_Up(t);
        }
        else if (t.train4_down == 0)
        {
            cout << "This train is full. Please select another train.\n\n";
            return Ticket_Purchase_Up(t);
        }
        t.train4_down -= num;
        t.jour4_price += price;
    }

    // Display the total cost of the booked seats
    cout << "\n\nThe cost of the seats is " << price * 2 << endl;
    return num; // Return the number of booked seats
}

int calculate_price(int num)
{
    if (num < 10)
    {
        return num * price;
    }
    else if (num >= 10 && num < 20)
    {
        return (num - 1) * price;
    }
    else if (num >= 20 && num < 30)
    {
        return (num - 2) * price;
    }
    else if (num >= 30 && num < 40)
    {
        return (num - 3) * price;
    }
    else if (num >= 40 && num < 50)
    {
        return (num - 4) * price;
    }
    else if (num >= 50 && num < 60)
    {
        return (num - 5) * price;
    }
    else if (num >= 60 && num < 70)
    {
        return (num - 6) * price;
    }
    else if (num >= 70 && num < 80)
    {
        return (num - 7) * price;
    }
    else
    {
        return (num - 8) * price;
    }
}