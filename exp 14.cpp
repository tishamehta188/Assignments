#include <iostream>
#include <vector>
#include <iomanip>

// Base class for items sold in the restaurant
class MenuItem {
protected:
    std::string name;
    double price;
public:
    MenuItem(const std::string& n, double p) : name(n), price(p) {}

    virtual double getPrice() const {
        return price;
    }

    virtual void display() const {
        std::cout << name << ": $" << std::fixed << std::setprecision(2) << price << std::endl;
    }
};

// Derived class for food items
class FoodItem : public MenuItem {
protected:
    std::string type;
public:
    FoodItem(const std::string& n, double p, const std::string& t) : MenuItem(n, p), type(t) {}

    void display() const override {
        std::cout << "Food - ";
        MenuItem::display();
    }
};

// Derived class for drinks
class DrinkItem : public MenuItem {
protected:
    std::string size;
public:
    DrinkItem(const std::string& n, double p, const std::string& s) : MenuItem(n, p), size(s) {}

    void display() const override {
        std::cout << "Drink - ";
        MenuItem::display();
    }
};

// Class representing a customer's order
class Order {
private:
    std::vector<MenuItem*> items;
public:
    void addItem(MenuItem* item) {
        items.push_back(item);
    }

    double calculateTotal() const {
        double total = 0;
        for (const auto& item : items) {
            total += item->getPrice();
        }
        return total;
    }

    void display() const {
        std::cout << "Items in the order:" << std::endl;
        for (const auto& item : items) {
            item->display();
        }
        std::cout << "Total: $" << std::fixed << std::setprecision(2) << calculateTotal() << std::endl;
    }
};

int main() {
    // Create some food items
    FoodItem burger("Burger", 7.99, "Fast Food");
    FoodItem pasta("Pasta", 9.99, "Italian");

    // Create some drink items
    DrinkItem coke("Coke", 1.99, "Regular");
    DrinkItem orangeJuice("Orange Juice", 2.49, "Large");

    // Create an order
    Order order;
    order.addItem(&burger);
    order.addItem(&coke);
    order.addItem(&pasta);
    order.addItem(&orangeJuice);

    // Display the order and total
    order.display();

    return 0;
}
