#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


class Product {
private:
    std::string name; //�����
    int productID; //ID
    double price; //����
    int quantity; //�������
    std::string category; //��������
    std::string brand; //�����
    int rating; //�������
    bool availability; //����������

public:
    //�����������
    Product(){}
    Product(std::string n, int id, double p, int q, std::string c, std::string b, int r, bool a) : name(n), productID(id), price(p), quantity(q), category(c), brand(b), rating(r), availability(a) {}

    //���,���
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

    //�������������� ����� ��� ���������� ������
    void restock(int amount) {
        quantity += amount;
        std::cout << "Restocked " << amount << " items." << std::endl;
    }

    //�������������� ����� � ���������� ����������
    void restock(int amount, bool newAvailability) {
        quantity += amount;
        availability = newAvailability;
        std::cout << "Restocked " << amount << " items. Availability updated." << std::endl;
    }

    //����� ��� ���������� ����� � ����
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << name << " " << productID << " " << price << " " << quantity << " " << category << " "
                << brand << " " << rating << " " << availability << std::endl;
            file.close();
        }
    }

    //����� ��� ������������ ����� � �����
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            file >> name >> productID >> price >> quantity >> category >> brand >> rating >> availability;
            file.close();
        }
    }
    //�������������� ����� ��� ��������� ���� �������� �� ����� (������ ��'��� �����)
    bool isMoreExpensiveThan(const Product& other) const {
        return this->price > other.price;
    }

    //����� ��� ��������� �������� �� �������
    bool isMoreExpensiveThan(const Product& other, double discount) const {
        double discountedPrice = this->price - (this->price * discount / 100);
        return discountedPrice > other.price;
    }

    //�������������� �����, ���� ������� ��'��� ����� Product
public:
    Product createDiscountedProduct(double discountPercent) const {
        double discountedPrice = price - (price * discountPercent / 100);
        return Product(name, productID, discountedPrice, quantity, category, brand, rating, availability);
    }

    //�������������� �����, ���� ������� ��'��� ����� � ��������� �������
    Product createDiscountedProduct(double discountPercent, int additionalQuantity) const {
        double discountedPrice = price - (price * discountPercent / 100);
        return Product(name, productID, discountedPrice, quantity + additionalQuantity, category, brand, rating, availability);
    }

    //���������� ����� ��� �������� ���'�� �� ���������� �����
    void dynamicMemoryAllocation(int size) {
        int* arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % 100;
        }

        //����������
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


