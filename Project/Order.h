#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Product.h"

class Order {
private:
    int orderID; // ID замовлення
    Product product; //продукт
    int quantity; //кількість
    double totalPrice; //загальна вартість
    std::string paymentMethod; //метод оплати
    bool isPaid; //статус оплати
    std::string deliveryAddress; //адреса доставки
    std::string orderStatus; //статус замовлення

public:
    Order(){}
    //конструктор
    Order(int id, const Product &p, int q, std::string pm, bool paid, std::string address, std::string status)
        : orderID(id), product(p), quantity(q), totalPrice(p.getPrice()* q), paymentMethod(pm), isPaid(paid), deliveryAddress(address), orderStatus(status) {}

    //гет, сет
    void setOrderID(int id) { orderID = id; }
    int getOrderID() const { return orderID; }

    void setProduct(Product p) { product = p; }
    Product getProduct() const { return product; }

    void setQuantity(int q) { quantity = q; }
    int getQuantity() const { return quantity; }

    void setTotalPrice(double tp) { totalPrice = tp; }
    double getTotalPrice() const { return totalPrice; }

    void setPaymentMethod(std::string pm) { paymentMethod = pm; }
    std::string getPaymentMethod() const { return paymentMethod; }

    void setIsPaid(bool paid) { isPaid = paid; }
    bool getIsPaid() const { return isPaid; }

    void setDeliveryAddress(std::string address) { deliveryAddress = address; }
    std::string getDeliveryAddress() const { return deliveryAddress; }

    void setOrderStatus(std::string status) { orderStatus = status; }
    std::string getOrderStatus() const { return orderStatus; }

    void updateOrder(const Order& other) {
        this->quantity = other.quantity;
        this->paymentMethod = other.paymentMethod;
        this->isPaid = other.isPaid;
        this->deliveryAddress = other.deliveryAddress;
        this->orderStatus = other.orderStatus;
    }

    void updateOrder(const Order& other, int additionalQuantity) {
        this->quantity = other.quantity + additionalQuantity;
        this->totalPrice = other.totalPrice + (additionalQuantity * other.product.getPrice());
        std::cout << "Order updated with additional quantity: " << additionalQuantity << std::endl;
    }

    Order getOrder() const {
        return *this;
    }

    Order getOrder(int additionalQuantity) const {
        Order newOrder = *this;
        newOrder.quantity += additionalQuantity;
        newOrder.totalPrice = newOrder.product.getPrice() * newOrder.quantity;
        return newOrder;
    }

    Order createNewOrder(int id, Product p, int q, std::string pm, bool paid, std::string address, std::string status) const {
        Order newOrder(id, p, q, pm, paid, address, status);
        return newOrder;
    }

    //метод для оплати замовлення
    void makePayment(std::string method) {
        paymentMethod = method;
        isPaid = true;
        std::cout << "Order paid with " << paymentMethod << std::endl;
    }

    //метод для збереження даних у файл
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << orderID << " " << product.getName() << " " << quantity << " " << totalPrice << " "
                << paymentMethod << " " << isPaid << " " << deliveryAddress << " " << orderStatus << std::endl;
            file.close();
        }
    }

    //метод для завантаження даних з файлу
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string productName;
            file >> orderID >> productName >> quantity >> totalPrice >> paymentMethod >> isPaid >> deliveryAddress >> orderStatus;
            product.setName(productName);
            file.close();
        }
    }
};
#endif
