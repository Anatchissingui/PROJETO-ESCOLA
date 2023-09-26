#include <iostream>
#include <vector>

struct MenuItem {
    int id;
    std::string name;
    std::string description;
    double price;
};

class Menu {
private:
    std::vector<MenuItem> menuItems;
    int nextId;

public:
    Menu() : nextId(1) {}

    void addItem(const std::string& name, const std::string& description, double price) {
        MenuItem item;
        item.id = nextId++;
        item.name = name;
        item.description = description;
        item.price = price;

        menuItems.push_back(item);
    }

    void updateItem(int id, const std::string& name, const std::string& description, double price) {
        for (auto& item : menuItems) {
            if (item.id == id) {
                item.name = name;
                item.description = description;
                item.price = price;
                break;
            }
        }
    }

    void deleteItem(int id) {
        for (auto it = menuItems.begin(); it != menuItems.end(); ++it) {
            if (it->id == id) {
                menuItems.erase(it);
                break;
            }
        }
    }

    MenuItem getItem(int id) {
        for (const auto& item : menuItems) {
            if (item.id == id) {
                return item;
            }
        }
        return MenuItem(); // Return an empty item if not found
    }

    std::vector<MenuItem> getAllItems() {
        return menuItems;
    }
};

int main() {
    Menu menu;

    // Add menu items
    menu.addItem("Café Latte", "Espresso with steamed milk", 3.5);
    menu.addItem("Croissant", "Buttery and flaky pastry", 2.0);
    menu.addItem("Fruit Salad", "Fresh assortment of seasonal fruits", 4.5);

    // Update an item
    menu.updateItem(2, "Almond Croissant", "Croissant filled with almond paste", 2.5);

    // Delete an item
    menu.deleteItem(3);

    // Get a specific item
    MenuItem item = menu.getItem(1);
    std::cout << "Item ID: " << item.id << std::endl;
    std::cout << "Item Name: " << item.name << std::endl;
    std::cout << "Item Description: " << item.description << std::endl;
    std::cout << "Item Price: $" << item.price << std::endl;

    // Get all items
    std::vector<MenuItem> items = menu.getAllItems();
    for (const auto& item : items) {
        std::cout << "Item ID: " << item.id << std::endl;
        std::cout << "Item Name: " << item.name << std::endl;
        std::cout << "Item Description: " << item.description << std::endl;
        std::cout << "Item Price: $" << item.price << std::endl;
        std::cout << std::endl;
    }

    return 0;
}