/*
 Title: TMA4Question2.cpp
 Description: Solution for Question 2 in TMA4
 Date: August 24, 2017
 Author: Vitor Mendonca
*/

/*
 DOCUMENTATION

 Program Purpose:
    Create a hierarchy of classes, using an abstract class and
    virtual functions, in order to study abstract inheritance in C++

 Compile (assuming Cygwin is running): make q2
 Execution (assuming Cygwin is running): ./q2

 Notes:
    - In Cygwin, main must return type int
    - Assumes C++11 (see Makefile for reference)

 Classes:
    Rodent: an abstract base class the represents typical behaviours
            for rodents.
    Mouse: a subclass of Rodent
    Rat: a subclass of Rodent
    Hamster: a subclass of Rodent
            for rodents.

 Variables:
    rodents: an array of 10 pointers to Rodents, used to test
             the abstract inheritance between Rodent and its
             subclasses
*/

/*
 TEST PLAN

 Normal case:
    >./q2
    >Rodent n. 0
    >Mouse is squeaking
    >Gnawing on cheese
    >Burrowing in the barn
    >Rodent n. 1
    >Rat is squeaking
    >Gnawing on trash
    >Burrowing in the sewer
    >Rodent n. 2
    >Hamster is squeaking
    >Gnawing on sunflower seeds
    >Burrowing in sawdust
    >Rodent n. 3
    >Mouse is squeaking
    >Gnawing on cheese
    >Burrowing in the barn
    >Rodent n. 4
    >Rat is squeaking
    >Gnawing on trash
    >Burrowing in the sewer
    >Rodent n. 5
    >Hamster is squeaking
    >Gnawing on sunflower seeds
    >Burrowing in sawdust
    >Rodent n. 6
    >Hamster is squeaking
    >Gnawing on sunflower seeds
    >Burrowing in sawdust
    >Rodent n. 7
    >Rat is squeaking
    >Gnawing on trash
    >Burrowing in the sewer
    >Rodent n. 8
    >Mouse is squeaking
    >Gnawing on cheese
    >Burrowing in the barn
    >Rodent n. 9
    >Rat is squeaking
    >Gnawing on trash
    >Burrowing in the sewer

 Discussion:
    The main function in this file has the purpose of testing
    the behaviour of the various classes.
    This program takes no input.

*/

#include <iostream>

class Rodent {
public:
    virtual ~Rodent() = default;

    virtual void squeak() = 0;

    virtual void gnaw() = 0;

    virtual void burrow() = 0;
};

class Mouse : public Rodent {
    void squeak() {
        std::cout << "Mouse is squeaking\n";
    }

    void gnaw() {
        std::cout << "Gnawing on cheese\n";
    }

    void burrow() {
        std::cout << "Burrowing in the barn\n";
    }
};

class Rat : public Rodent {
    void squeak() {
        std::cout << "Rat is squeaking\n";
    }

    void gnaw() {
        std::cout << "Gnawing on trash\n";
    }

    void burrow() {
        std::cout << "Burrowing in the sewer\n";
    }
};

class Hamster : public Rodent {
    void squeak() {
        std::cout << "Hamster is squeaking\n";
    }

    void gnaw() {
        std::cout << "Gnawing on sunflower seeds\n";
    }

    void burrow() {
        std::cout << "Burrowing in sawdust\n";
    }
};

int main() {
    Rodent* rodents[] = {
        new Mouse(),
        new Rat(),
        new Hamster(),
        new Mouse(),
        new Rat(),
        new Hamster(),
        new Hamster(),
        new Rat(),
        new Mouse(),
        new Rat()
    };

    for (int i = 0; i < 10; ++i) {
        std::cout << "Rodent n. " << i << '\n';
        rodents[i]->squeak();
        rodents[i]->gnaw();
        rodents[i]->burrow();
    }


    for (Rodent* r : rodents) {
        delete r;
    }
}
