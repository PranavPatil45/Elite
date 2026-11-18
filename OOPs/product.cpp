
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

class Product
{
protected:
    int id;
    string name;
    double price;
    int quantity;

public:
    Product(int i, string n, double p, int q)
    {
        if (p <= 0 || q < 0)
            throw "Invalid price or quantity.";

        id = i;
        name = n;
        price = p;
        quantity = q;
    }

    int getID() const
    {
        return id;
    }

    double getPrice() const
    {
        return price;
    }

    // Overload < operator
    bool operator<(const Product &p) const
    {
        return price < p.price;
    }

    void updateQuantity(int q)
    {
        if (q < 0)
            throw "Quantity cannot be negative.";

        quantity = q;
    }

    virtual void display() const
    {
        cout << id << "\t"
             << name << "\t"
             << price << "\t"
             << quantity << "\t"
             << "General" << endl;
    }

    virtual void save(ofstream &file) const
    {
        file << id << "," << name << ","
             << price << "," << quantity << ",G\n";
    }

    virtual ~Product() {}
};

class Electronic : public Product
{
public:
    Electronic(int i, string n, double p, int q)
        : Product(i, n, p, q) {}

    void display() const override
    {
        cout << id << "\t" << name << "\t"
             << price << "\t" << quantity
             << "\tElectronic" << endl;
    }

    void save(ofstream &file) const override
    {
        file << id << "," << name << ","
             << price << "," << quantity << ",E\n";
    }
};

class Furniture : public Product
{
public:
    Furniture(int i, string n, double p, int q)
        : Product(i, n, p, q) {}

    void display() const override
    {
        cout << id << "\t" << name << "\t"
             << price << "\t" << quantity
             << "\tFurniture" << endl;
    }

    void save(ofstream &file) const override
    {
        file << id << "," << name << ","
             << price << "," << quantity << ",F\n";
    }
};

int main()
{
    vector<Product *> products;
    ifstream fin("products.txt");

    if (!fin)
    {
        cout << "Error opening input file.\n";
        return 1;
    }

    string line;

    try
    {
        while (getline(fin, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string field, name, category;
            int id, quantity;
            double price;

            if (!getline(ss, field, ','))
                throw "Invalid product record.";
            id = stoi(field);

            if (!getline(ss, name, ',') ||
                !getline(ss, field, ','))
                throw "Invalid product record.";
            price = stod(field);

            if (!getline(ss, field, ','))
                throw "Missing quantity.";
            quantity = stoi(field);

            if (!getline(ss, category))
                throw "Missing category.";

            Product *p = nullptr;

            if (category == "E")
                p = new Electronic(id, name, price, quantity);
            else if (category == "F")
                p = new Furniture(id, name, price, quantity);
            else
                throw "Invalid product category.";

            bool duplicate = false;

            for (Product *existing : products)
            {
                if (existing->getID() == id)
                {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate)
            {
                cout << "Duplicate product ID skipped: "
                     << id << endl;
                delete p;
            }
            else
            {
                products.push_back(p);
            }
        }

        fin.close();

        int choice;

        do
        {
            cout << "\n--- PRODUCT INVENTORY ---\n";
            cout << "1. Display Products by Price\n";
            cout << "2. Search Product by ID\n";
            cout << "3. Update Product Quantity\n";
            cout << "4. Save Products to File\n";
            cout << "5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                sort(products.begin(), products.end(),
                     [](Product *a, Product *b)
                     {
                         return *a < *b;
                     });

                cout << "\nID\tName\tPrice\tQuantity\tCategory\n";

                for (Product *p : products)
                    p->display();

                break;

            case 2:
            {
                int id;
                cout << "Enter Product ID: ";
                cin >> id;

                bool found = false;

                for (Product *p : products)
                {
                    if (p->getID() == id)
                    {
                        p->display();
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Product not found.\n";

                break;
            }

            case 3:
            {
                int id, q;
                bool found = false;

                cout << "Enter Product ID: ";
                cin >> id;

                for (Product *p : products)
                {
                    if (p->getID() == id)
                    {
                        cout << "Enter new quantity: ";
                        cin >> q;

                        p->updateQuantity(q);

                        cout << "Quantity updated successfully.\n";
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Product not found.\n";

                break;
            }

            case 4:
            {
                ofstream fout("products.txt");

                if (!fout)
                    throw "Error opening output file.";

                for (Product *p : products)
                    p->save(fout);

                fout.close();

                cout << "Products saved successfully.\n";
                break;
            }

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
            }
        } while (choice != 5);
    }
    catch (const char *msg)
    {
        cout << "Exception: " << msg << endl;
    }
    catch (...)
    {
        cout << "Error: Invalid data in the input file.\n";
    }

    for (Product *p : products)
        delete p;

    return 0;
}
