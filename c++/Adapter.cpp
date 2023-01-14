#include <iostream>
#include <memory>
#include <string>

struct Item {
    Item(std::string&& itemName)
        :name(std::move(itemName)){}

    std::string name;
};

class Target {
public:
    virtual ~Target() = default;

    virtual Item Operation() const {
        return Item("Target defauld operation!\n");
    }
};

class Adaptee {
public:
    std::string Operation() const {
        return "Adaptee operation!\n";
    }
};

class Adapter : public Target {
private:
    std::shared_ptr<Adaptee> adaptee;

    public:
    Adapter(std::shared_ptr<Adaptee> ad) : adaptee(ad) {}

    Item Operation() const override {
        std::string smth = adaptee->Operation();
        return Item(std::move(smth));
    }
};

void ClientCode(std::shared_ptr<Target> target) {
  std::cout << target->Operation().name;
}

int main() {
  std::shared_ptr<Target> target = std::make_shared<Target>();
  ClientCode(target);

  std::shared_ptr<Adaptee> adaptee = std::make_shared<Adaptee>();
  std::shared_ptr<Adapter> adapter = std::make_shared<Adapter>(adaptee);

  ClientCode(adapter);

  return 0;
}
