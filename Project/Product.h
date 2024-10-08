#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


class Product {
private:
    std::string name; //назва
    int productID; //ID
    double price; //ціна
    int quantity; //кількість
    std::string category; //категорія
    std::string brand; //бренд
    int rating; //рейтинг
    bool availability; //доступність

public:
    //конструктор
    Product(){}
    Product(std::string n, int id, double p, int q, std::string c, std::string b, int r, bool a) : name(n), productID(id), price(p), quantity(q), category(c), brand(b), rating(r), availability(a) {}

    //гет,сет
        void setName(std::string n) { name = n; }
        std::string getName() const { return name; }

        void setProductID(int id) { productID = id; }
        int getProductID() const { return productID; }

        void setPrice(double p) { price = p; }
        double getPrice() const { return price; }

        void setQuantity(int q) { quantity = q; }
        int getQuantity() const { return quantity; }

        void setCategory(std::string c) { category = c; }
        std::string getCategory() const { return category; }

        void setBrand(std::string b) { brand = b; }
        std::string getBrand() const { return brand; }

        void setRating(int r) { rating = r; }
        int getRating() const { return rating; }

        void setAvailability(bool a) { availability = a; }
        bool isAvailable() const { return availability; }

    //перевантажений метод для поповнення запасу
    void restock(int amount) {
        quantity += amount;
        std::cout << "Restocked " << amount << " items." << std::endl;
    }

    //перевантажений метод з оновленням доступності
    void restock(int amount, bool newAvailability) {
        quantity += amount;
        availability = newAvailability;
        std::cout << "Restocked " << amount << " items. Availability updated." << std::endl;
    }

    //метод для збереження даних у файл
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << name << " " << productID << " " << price << " " << quantity << " " << category << " "
                << brand << " " << rating << " " << availability << std::endl;
            file.close();
        }
    }

    //метод для завантаження даних з файлу
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            file >> name >> productID >> price >> quantity >> category >> brand >> rating >> availability;
            file.close();
        }
    }
    //перевантажений метод для порівняння двох продуктів за ціною (приймає об'єкт класу)
    bool isMoreExpensiveThan(const Product& other) const {
        return this->price > other.price;
    }

    //метод для порівняння продуктів по кількості
    bool isMoreExpensiveThan(const Product& other, double discount) const {
        double discountedPrice = this->price - (this->price * discount / 100);
        return discountedPrice > other.price;
    }

    //перевантажений метод, який повертає об'єкт класу Product
public:
    Product createDiscountedProduct(double discountPercent) const {
        double discountedPrice = price - (price * discountPercent / 100);
        return Product(name, productID, discountedPrice, quantity, category, brand, rating, availability);
    }

    //перевантажений метод, який повертає об'єкт класу з оновленою кількістю
    Product createDiscountedProduct(double discountPercent, int additionalQuantity) const {
        double discountedPrice = price - (price * discountPercent / 100);
        return Product(name, productID, discountedPrice, quantity + additionalQuantity, category, brand, rating, availability);
    }

    //додатковий метод для виділення пам'яті та сортування чисел
    void dynamicMemoryAllocation(int size) {
        int* arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % 100;
        }

        //сортування
        std::sort(arr, arr + size);
        std::cout << "Sorted values: ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        delete[] arr;
    }
};

#endif


