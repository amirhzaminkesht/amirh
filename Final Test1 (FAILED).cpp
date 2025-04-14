#include <iostream>
#include <string>
using namespace std;

//---------------------------
// Part 1: Define the Structure for Inventory Items
//---------------------------

struct Item {
    string name;
    int quantity;
    double price;

    // Parameterized Constructor: Allows easy initialization like Item("Widget", 10, 1.99)
    Item(const string& itemName, int itemQuantity, double itemPrice)
        : name(itemName), quantity(itemQuantity), price(itemPrice) {}

    // Default Constructor: Required when allocating an array of Items.
    Item() : name(""), quantity(0), price(0.0) {}
};

//---------------------------
// Part 2: Inventory Class for Managing Items
//---------------------------

class Inventory {
private:
    Item* items;       // Dynamic array of Item objects
    int itemCount;     // Current number of items stored
    int capacity;      // Maximum capacity of our dynamic array

    // Private helper function to double the capacity when the array is full.
    void resize() {
        int newCapacity = capacity * 2;
        Item* newItems = new Item[newCapacity];
        // Copy existing items into the new array.
        for (int i = 0; i < itemCount; ++i) {
            newItems[i] = items[i];
        }
        delete[] items;   // Free the old memory
        items = newItems; // Point to the newly allocated array
        capacity = newCapacity;
    }

public:
    // Default constructor: Sets up an initial small capacity.
    Inventory() : itemCount(0), capacity(2) {
        items = new Item[capacity];
    }

    // Destructor: Ensures we deallocate the dynamic memory to prevent memory leaks.
    ~Inventory() {
        delete[] items;
    }

    // Copy Constructor (Advanced): Performs a deep copy to keep separate copies of data.
    Inventory(const Inventory& other) : itemCount(other.itemCount), capacity(other.capacity) {
        items = new Item[capacity];
        for (int i = 0; i < itemCount; ++i)
            items[i] = other.items[i];
    }

    // Assignment Operator (Advanced): Ensures deep copy and proper memory management.
    Inventory& operator=(const Inventory& other) {
        if (this != &other) {
            delete[] items; // Free current memory
            itemCount = other.itemCount;
            capacity = other.capacity;
            items = new Item[capacity];
            for (int i = 0; i < itemCount; ++i)
                items[i] = other.items[i];
        }
        return *this;
    }

    // Add Item: Adds a new item to the inventory. Resizes the array if needed.
    void addItem(const Item& newItem) {
        if (itemCount == capacity) {
            resize();
        }
        items[itemCount++] = newItem;
    }

    // Remove Item: Removes an item by name and returns true if successful.
    bool removeItem(const string& itemName) {
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].name == itemName) {
                // Shift the array to remove the gap.
                for (int j = i; j < itemCount - 1; ++j) {
                    items[j] = items[j + 1];
                }
                --itemCount;
                return true;
            }
        }
        return false; // Item not found.
    }

    // Update Quantity: Searches by item name and updates the quantity.
    void updateQuantity(const string& itemName, int newQuantity) {
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].name == itemName) {
                items[i].quantity = newQuantity;
                return;
            }
        }
        cerr << "Item \"" << itemName << "\" not found in inventory.\n";
    }

    // Overloaded operator[]: Enables array-like access to inventory items.
    Item& operator[](int index) {
        if (index >= 0 && index < itemCount)
            return items[index];
        throw out_of_range("Index out of range");
    }

    // Overloaded operator<<: Allows easy printing of the entire inventory.
    friend ostream& operator<<(ostream& os, const Inventory& inventory) {
        os << "Inventory details:\n";
        for (int i = 0; i < inventory.itemCount; ++i) {
            os << "Item " << i + 1 << ":\n";
            os << "  Name: " << inventory.items[i].name << "\n";
            os << "  Quantity: " << inventory.items[i].quantity << "\n";
            os << "  Price: $" << inventory.items[i].price << "\n";
        }
        return os;
    }

    // Getter for total number of items, which will be used by one of our print functions.
    int getItemCount() const {
        return itemCount;
    }
};

//---------------------------
// Part 3: Overloaded Print Functions
//---------------------------

// Print function that accepts an integer (e.g., total number of items)
void print(int totalItems) {
    cout << "Total number of items: " << totalItems << "\n";
}

// Print function that accepts a single Item and prints its details in a formatted style.
void print(const Item& item) {
    cout << "Item Details:\n";
    cout << "  Name: " << item.name << "\n";
    cout << "  Quantity: " << item.quantity << "\n";
    cout << "  Price: $" << item.price << "\n";
}

//---------------------------
// Part 4: main() Using References, Pointers, and Parameter Passing
//---------------------------

int main() {
    // Create an Inventory instance on the stack.
    Inventory inventory;

    // Dynamically allocate an Inventory object using a pointer.
    Inventory* inventoryPtr = new Inventory();

    // -----------------------------
    // Manipulate Data
    // -----------------------------

    // Adding several items using addItem function.
    inventory.addItem(Item("Widget", 10, 1.99));
    inventory.addItem(Item("Gadget", 5, 4.99));
    inventory.addItem(Item("Thingamajig", 20, 2.49));

    // Add items to the dynamically allocated Inventory.
    inventoryPtr->addItem(Item("Doohickey", 15, 3.99));
    inventoryPtr->addItem(Item("Contraption", 8, 9.99));

    // Update the quantity of a specific item.
    inventory.updateQuantity("Widget", 12);

    // -----------------------------
    // Demonstrate Access with Overloaded operator[]
    // -----------------------------
    try {
        // Use the overloaded operator[] to access the first item.
        Item& firstItem = inventory[0];

        // Modify the item's quantity directly using the reference.
        firstItem.quantity = 100;

        cout << "\nAfter modifying the first item using operator[]:\n";
        print(firstItem);  // Use the print overload for a single Item.
    } catch (const out_of_range& ex) {
        cerr << ex.what() << "\n";
    }

    // -----------------------------
    // Use Overloaded Print Functions
    // -----------------------------
    // Print the total number of items in the inventory.
    print(inventory.getItemCount());

    // Use the overloaded << operator to print the entire inventory.
    cout << "\nInventory (stack instance):\n" << inventory;

    // Print the dynamically allocated inventory.
    cout << "\nInventory (dynamically allocated instance):\n" << *inventoryPtr;

    // -----------------------------
    // Clean Up
    // -----------------------------
    delete inventoryPtr;  // Free the dynamically allocated Inventory object.

    return 0;
}
