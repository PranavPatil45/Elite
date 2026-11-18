#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    int code;
    string name;
    int availableQ;
    float price;

public:
    void acceptDetails()
    {
        cout << "Enter code of Product: ";
        cin >> code;
        cin.ignore();

        cout << "Enter Product name: ";
        getline(cin, name);

        cout << "Enter number of Products: ";
        cin >> availableQ;

        cout << "Enter price of unit product: ";
        cin >> price;
    }

    int getProductCode()
    {
        return code;
    }

    void displayDetails()
    {
        cout << "Product code: " << code << endl;
        cout << "Product name: " << name << endl;
        cout << "Available quantity: " << availableQ << endl;
        cout << "Product Unit Price: " << price << endl;
        cout << "\n";
    }

    void updatePrice(float p)
    {
        price = p;
    }

    void updateQuantity(int q)
    {
        availableQ = q;
    }
};
int main()
{
    Product products[100];
    int n = 0, id, choice;
    int q;
    bool found = false;
    float newprice;

    do
    {
        cout << "1. Enter product details\n";
        cout << "2. Display complete inventory\n";
        cout << "3. Search for a product using product code\n";
        cout << "4. Update the price of a product\n";
        cout << "5. Update the quantity of a product\n";
        cout << "6. Exit\n\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            products[n].acceptDetails();
            n++;
            break;

        case 2:
            for (int i = 0; i < n; i++)
            {
                products[i].displayDetails();
            }
            break;

        case 3:
            found = false;
            cout << "Enter code of product to search: ";
            cin >> id;

            for (int i = 0; i < n; i++)
            {
                if (products[i].getProductCode() == id)
                {
                    cout << "Product found" << endl;
                    found = true;
                    products[i].displayDetails();
                    break;
                }
            }
            if (!found)
            {
                cout << "Product not found" << endl;
            }
            break;

        case 4:
            found = false;
            cout << "Enter code of product to update price: ";
            cin >> id;
            for (int i = 0; i < n; i++)
            {
                if (products[i].getProductCode() == id)
                {
                    found = true;
                    cout << "Enter new Price: ";
                    cin >> newprice;
                    products[i].updatePrice(newprice);
                    break;
                }
            }
            if (!found)
            {
                cout << "Product not found" << endl;
            }
            break;

        case 5:
            found = false;
            cout << "Enter code of product to update quantity: ";
            cin >> id;
            for (int i = 0; i < n; i++)
            {
                if (products[i].getProductCode() == id)
                {
                    found = true;
                    cout << "Enter new quantity: ";
                    cin >> q;
                    products[i].updateQuantity(q);
                    break;
                }
            }
            if (!found)
            {
                cout << "Product not found" << endl;
            }
            break;

        case 6:
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
