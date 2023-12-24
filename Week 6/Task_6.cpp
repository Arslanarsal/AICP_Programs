#include <iostream>
#include <string>

using namespace std;

const double CEMENT_MIN_WEIGHT = 24.9;
const double CEMENT_MAX_WEIGHT = 25.1;
const double GRAVEL_SAND_MIN_WEIGHT = 49.9; 
const double GRAVEL_SAND_MAX_WEIGHT = 50.1;

const double CEMENT_PRICE = 3.0;
const double GRAVEL_PRICE = 2.0;
const double SAND_PRICE = 2.0;
const double SPECIAL_PACK_PRICE = 10.0;

double numCementp;
double numGravelp;
double numSandp;

struct Sack
{
    char content;
    double weight;
};

// Task 1 - Check the contents and weight of a single sack
bool checkSack(Sack sack)
{
    if (sack.content == 'C')
    {
        if (sack.weight >= CEMENT_MIN_WEIGHT && sack.weight <= CEMENT_MAX_WEIGHT)
        {
            cout << "Accepted sack - Content: Cement, Weight: " << sack.weight << " kg" << endl;
            return true;
        }
        else
        {
            cout << "Rejected sack - Incorrect weight for cement" << endl;
            numCementp--;
            return false;
        }
    }
    else if (sack.content == 'G' || sack.content == 'S')
    {
        if (sack.weight >= GRAVEL_SAND_MIN_WEIGHT && sack.weight <= GRAVEL_SAND_MAX_WEIGHT)
        {
            cout << "Accepted sack - Content: " << (sack.content == 'G' ? "Gravel" : "Sand") << ", Weight: " << sack.weight << " kg" << endl;
            return true;
        }
        else
        {
            cout << "Rejected sack - Incorrect weight for gravel/sand" << endl;
            if (sack.content == 'G')
            {
                numGravelp--;
            }
            else
            {
                numSandp--;
            }

            return false;
        }
    }
    else
    {
        cout << "Rejected sack - Invalid content" << endl;
        return false;
    }
}

// Task 2 - Check a customer’s order for delivery
void checkOrder()
{
    int numCement, numGravel, numSand;
    int rejectedSacks = 0;
    double totalWeight = 0.0;

    cout << "Enter the number of sacks of cement: ";
    cin >> numCement;
    numCementp = numCement;
    cout << "Enter the number of sacks of gravel: ";
    cin >> numGravel;
    numGravelp = numGravel;
    cout << "Enter the number of sacks of sand: ";
    cin >> numSand;
    numSandp = numSand;
    cout << "\n\n\n";
    for (int i = 0; i < numCement; ++i)
    {
        Sack sack;
        sack.content = 'C';
        cout << "Enter the weight for cement sack " << i + 1 << ": ";
        cin >> sack.weight;
        if (!checkSack(sack))
        {
            rejectedSacks++;
        }
        else
        {
            totalWeight += sack.weight;
        }
    }

    for (int i = 0; i < numGravel; ++i)
    {
        Sack sack;
        sack.content = 'G';
        cout << "Enter the weight for gravel sack " << i + 1 << ": ";
        cin >> sack.weight;
        if (!checkSack(sack))
        {
            rejectedSacks++;
        }
        else
        {
            totalWeight += sack.weight;
        }
    }

    for (int i = 0; i < numSand; ++i)
    {
        Sack sack;
        sack.content = 'S';
        cout << "Enter the weight for sand sack " << i + 1 << ": ";
        cin >> sack.weight;
        if (!checkSack(sack))
        {
            rejectedSacks++;
        }
        else
        {
            totalWeight += sack.weight;
        }
    }

    cout << "Total weight of the order: " << totalWeight << " kg" << endl;
    cout << "Number of sacks rejected from the order: " << rejectedSacks << endl;
}

// Task 3 - Calculate the price for a customer’s order
void calculatePrice()
{
    double regularPrice = (numCementp * CEMENT_PRICE) + (numGravelp * GRAVEL_PRICE) + (numSandp * SAND_PRICE);

    int specialPacks = min(numCementp, min(numGravelp / 2, numSandp / 2));

    double discountedPrice = regularPrice;
    double amountSaved = 0.0;

    if (specialPacks > 0)
    {
        int specialPackCount = specialPacks;
        discountedPrice -= specialPackCount * SPECIAL_PACK_PRICE;
        amountSaved = specialPackCount * (CEMENT_PRICE + 2 * GRAVEL_PRICE + 2 * SAND_PRICE);
    }

    cout << "Regular price for the order: $" << regularPrice << endl;

    if (specialPacks > 0)
    {
        cout << "Special packs applied: " << specialPacks << endl;
        cout << "Discounted price for the order: $" << discountedPrice << endl;
        cout << "You saved: $" << amountSaved << endl;
    }
    else
    {
        cout << "No special packs applied. Final price: $" << regularPrice << endl;
    }
}

int main()
{
    checkOrder();
    calculatePrice();
    return 0;
}
