#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using namespace std;

// --- Utility Functions ---
void clearScreen() {
    system("cls || clear");

}

void pauseScreen() {
    cout << "\n\n\t\t Press Enter to continue...";
    cin.ignore(10000, '\n');
    cin.get();
}

// --- Data Models (Classes) ---

class Dealer {
public:
    int id;
    char name[30];
    char phone[15];

    void getdata() {
        cout << "\n\t\t Enter Dealer ID   : "; cin >> id;
        cin.ignore();
        cout << "\t\t Enter Dealer Name : "; cin.getline(name, 30);
        cout << "\t\t Enter Phone No    : "; cin.getline(phone, 15);
    }
    void showdata() {
        cout << "\n\t " << setw(5) << id << " | " << setw(20) << name << " | " << phone;
    }
};

class Product {
public:
    int id;
    char name[30];
    int dealer_id;
    float purchase_price;
    float selling_price;
    int qty;

    void getdata() {
        cout << "\n\t\t Enter Product ID     : "; cin >> id;
        cin.ignore();
        cout << "\t\t Enter Product Name   : "; cin.getline(name, 30);
        cout << "\t\t Assign Dealer ID     : "; cin >> dealer_id;
        cout << "\t\t Enter Purchase Price : "; cin >> purchase_price;
        cout << "\t\t Enter Selling Price  : "; cin >> selling_price;
        cout << "\t\t Enter Stock Quantity : "; cin >> qty;
    }
    void showdata() {
        cout << "\n\t " << setw(5) << id << " | " << setw(15) << name << " | D-ID: " << setw(3) << dealer_id 
             << " | Price: " << setw(6) << selling_price << " | Stock: " << qty;
    }
};

class Customer {
public:
    int id;
    char name[30];
    char phone[15];

    void getdata() {
        cout << "\n\t\t Enter Customer ID   : "; cin >> id;
        cin.ignore();
        cout << "\t\t Enter Customer Name : "; cin.getline(name, 30);
        cout << "\t\t Enter Phone No      : "; cin.getline(phone, 15);
    }
    void showdata() {
        cout << "\n\t " << setw(5) << id << " | " << setw(20) << name << " | " << phone;
    }
};

class Sale {
public:
    int bill_no;
    int cust_id;
    int prod_id;
    int qty_sold;
    float total_amount;
    float profit;

    void showdata() {
        cout << "\n\t Bill: " << setw(4) << bill_no << " | Cust: " << setw(4) << cust_id 
             << " | Prod: " << setw(4) << prod_id << " | Qty: " << setw(3) << qty_sold 
             << " | Total: " << setw(6) << total_amount << " | Profit: " << profit;
    }
};

// --- Function Prototypes ---
void manage_dealers();
void manage_products();
void manage_customers();
void generate_bill();
void view_reports();

// --- Main Menu ---
int main() {
    int choice;
    do {
        clearScreen();
        cout << "\n\n\t\t==================================";
        cout << "\n\t\t     GROCERY MANAGEMENT SYSTEM";
        cout << "\n\t\t==================================\n";
        cout << "\n\t\t 1. Dealer Management";
        cout << "\n\t\t 2. Product & Inventory Management";
        cout << "\n\t\t 3. Customer Management";
        cout << "\n\t\t 4. Generate Bill & Sales";
        cout << "\n\t\t 5. View Sales & Profit Reports";
        cout << "\n\t\t 6. Exit\n";
        cout << "\n\t\t Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manage_dealers(); break;
            case 2: manage_products(); break;
            case 3: manage_customers(); break;
            case 4: generate_bill(); break;
            case 5: view_reports(); break;
            case 6: break;
            default: cout << "\n\t\t Invalid choice!"; pauseScreen(); break;
        }
    } while (choice != 6);
    return 0;
}

// --- Dealer Module ---
void manage_dealers() {
    int ch;
    fstream f;
    Dealer d;
    do {
        clearScreen();
        cout << "\n\t\t--- DEALER MANAGEMENT ---\n";
        cout << "\t\t1. Add Dealer\n\t\t2. View Dealers\n\t\t3. Back\n\t\tChoice: ";
        cin >> ch;
        if (ch == 1) {
            f.open("dealer.dat", ios::app | ios::binary);
            d.getdata();
            f.write((char*)&d, sizeof(d));
            f.close();
            cout << "\n\t\t Dealer Added Successfully!";
            pauseScreen();
        } else if (ch == 2) {
            f.open("dealer.dat", ios::in | ios::binary);
            if (!f) { cout << "\n\t\t No records found!"; } 
            else {
                cout << "\n\t ID    | Name                 | Phone";
                cout << "\n\t-------------------------------------------------";
                while (f.read((char*)&d, sizeof(d))) d.showdata();
            }
            f.close();
            pauseScreen();
        }
    } while (ch != 3);
}

// --- Product Module (Linked to Dealer) ---
void manage_products() {
    int ch;
    fstream f, fd;
    Product p;
    Dealer d;
    do {
        clearScreen();
        cout << "\n\t\t--- PRODUCT & INVENTORY ---\n";
        cout << "\t\t1. Add Product\n\t\t2. View Products (Stock)\n\t\t3. Back\n\t\tChoice: ";
        cin >> ch;
        if (ch == 1) {
            // Show available dealers first to ensure relational integrity
            fd.open("dealer.dat", ios::in | ios::binary);
            if (!fd) { cout << "\n\t\t Please add a Dealer first!"; pauseScreen(); continue; }
            cout << "\n\t\t Available Dealers:";
            while (fd.read((char*)&d, sizeof(d))) { cout << "\n\t\t ID: " << d.id << " - Name: " << d.name; }
            fd.close();
            cout << "\n";

            f.open("prod.dat", ios::app | ios::binary);
            p.getdata();
            f.write((char*)&p, sizeof(p));
            f.close();
            cout << "\n\t\t Product Added Successfully!";
            pauseScreen();
        } else if (ch == 2) {
            f.open("prod.dat", ios::in | ios::binary);
            if (!f) { cout << "\n\t\t No records found!"; } 
            else {
                while (f.read((char*)&p, sizeof(p))) p.showdata();
            }
            f.close();
            pauseScreen();
        }
    } while (ch != 3);
}

// --- Customer Module ---
void manage_customers() {
    int ch;
    fstream f;
    Customer c;
    do {
        clearScreen();
        cout << "\n\t\t--- CUSTOMER MANAGEMENT ---\n";
        cout << "\t\t1. Add Customer\n\t\t2. View Customers\n\t\t3. Back\n\t\tChoice: ";
        cin >> ch;
        if (ch == 1) {
            f.open("cust.dat", ios::app | ios::binary);
            c.getdata();
            f.write((char*)&c, sizeof(c));
            f.close();
            cout << "\n\t\t Customer Added Successfully!";
            pauseScreen();
        } else if (ch == 2) {
            f.open("cust.dat", ios::in | ios::binary);
            if (!f) { cout << "\n\t\t No records found!"; } 
            else {
                while (f.read((char*)&c, sizeof(c))) c.showdata();
            }
            f.close();
            pauseScreen();
        }
    } while (ch != 3);
}

// --- Billing & Sales Engine ---
void generate_bill() {
    clearScreen();
    fstream fc, fp_disp, fp, fs;
    Customer c;
    Product p;
    Sale s;
    int c_id, p_id, req_qty;
    bool found = false;

    cout << "\n\t\t--- GENERATE BILL ---\n";
    cout << "\t\t Enter Bill Number : "; 
    cin >> s.bill_no;

    fc.open("cust.dat", ios::in | ios::binary);
    if (!fc) { 
        cout << "\n\t\t Customer Database Empty! Please add a customer first."; 
        pauseScreen(); 
        return; 
    }
    cout << "\n\t\t --- AVAILABLE CUSTOMERS ---";
    while (fc.read((char*)&c, sizeof(c))) {
        c.showdata();
    }
    fc.close();
    
    cout << "\n\n\t\t Enter Customer ID : "; 
    cin >> c_id;

    fp_disp.open("prod.dat", ios::in | ios::binary);
    if (!fp_disp) { 
        cout << "\n\t\t Product Database Empty! Please add a product first."; 
        pauseScreen(); 
        return; 
    }
    cout << "\n\n\t\t --- AVAILABLE PRODUCTS (STOCK) ---";
    while (fp_disp.read((char*)&p, sizeof(p))) {
        p.showdata();
    }
    fp_disp.close();

    cout << "\n\n\t\t Enter Product ID  : "; 
    cin >> p_id;
    cout << "\t\t Enter Quantity    : "; 
    cin >> req_qty;

    fp.open("prod.dat", ios::in | ios::out | ios::binary);
    
    while (fp.read((char*)&p, sizeof(p))) {
        if (p.id == p_id) {
            found = true;
            if (p.qty >= req_qty) {
                s.cust_id = c_id;
                s.prod_id = p_id;
                s.qty_sold = req_qty;
                s.total_amount = p.selling_price * req_qty;
                s.profit = (p.selling_price - p.purchase_price) * req_qty;

                p.qty -= req_qty;
                int pos = fp.tellg();
                fp.seekp(pos - sizeof(p));
                fp.write((char*)&p, sizeof(p));

                fs.open("sales.dat", ios::app | ios::binary);
                fs.write((char*)&s, sizeof(s));
                fs.close();

                cout << "\n\t\t Bill Generated! Total Amount: Rs." << s.total_amount;
            } else {
                cout << "\n\t\t Insufficient Stock! Only " << p.qty << " available.";
            }
            break;
        }
    }
    if (!found) cout << "\n\t\t Product ID not found!";
    fp.close();
    pauseScreen();
}

// --- Reports & Profit Module ---
void view_reports() {
    clearScreen();
    fstream f;
    Sale s;
    float total_revenue = 0, total_profit = 0;

    cout << "\n\t\t--- SALES & PROFIT REPORT ---\n";
    f.open("sales.dat", ios::in | ios::binary);
    if (!f) { 
        cout << "\n\t\t No sales recorded yet."; 
    } else {
        while (f.read((char*)&s, sizeof(s))) {
            s.showdata();
            total_revenue += s.total_amount;
            total_profit += s.profit;
        }
        cout << "\n\n\t-------------------------------------------------";
        cout << "\n\t\t TOTAL REVENUE : Rs. " << total_revenue;
        cout << "\n\t\t TOTAL PROFIT  : Rs. " << total_profit;
        cout << "\n\t-------------------------------------------------";
    }
    f.close();
    pauseScreen();
}