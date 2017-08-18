#include <iostream>

class Rodent {
public:
    virtual void squeak() = 0;

    virtual void gnaw() = 0;

    virtual void burrow() = 0;
};

class Mouse : public Rodent {
    void squeak() {
        std::cout << "Mouse is squeaking";
    }

    void gnaw() {
        std::cout << "Gnawing on cheese";
    }

    void burrow() {
        std::cout << "Burrowing in the barn";
    }
};

int main() {
}
