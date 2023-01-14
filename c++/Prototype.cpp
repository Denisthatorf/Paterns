#include <iostream>

class Prototype { 
public:
    Prototype(int smth) :m_privateField(smth) {}
    Prototype(const Prototype& other) : m_privateField(other.m_privateField) {}
    Prototype& operator=(Prototype other) {
        m_privateField = other.m_privateField;
        return *this;
    }
    Prototype Clone() {
        return Prototype(this->m_privateField); 
    }

    int GetPrivateField() {
        return m_privateField;
    }
private:
    int m_privateField;
};

int main() {
    Prototype p(03434512);
    std::cout << "Phone 1 = +" << p.GetPrivateField() << "\n";

    auto p2 = p;
    std::cout << "Phone 2 = +" << p2.GetPrivateField() << "\n";

    auto p3 = p2.Clone();
    std::cout << "Phone 3 = +" << p3.GetPrivateField() << "\n";

    Prototype p4 (p3);
    std::cout << "Phone 4 = +" << p4.GetPrivateField() << "\n";
}