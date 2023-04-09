#pragma once

#include "Point2D.h"

class Character {

private:

    string name;        // private member variable to store the character's name
    Point2D location;   // private member variable to store the character's current location
    bool npc;           // private member variable to indicate whether the character is controlled by the computer (non-player character or NPC)

public:

    Character(const std::string& name, const Point2D& location, bool npcFlag = 0)
        : name(name), location(location), npc(npcFlag) {   }  // constructor for the Character class which initializes the private member variables

    void moveTo(int direction, int steps) {  // method to move the character in a specific direction for a certain number of steps

        int deltaX(0), deltaY(0);   // local variables to store the change in x and y coordinates

        switch (direction)  // switch statement to determine the change in x and y coordinates based on the specified direction
        {
        case 0:
            deltaY = 1;
            break;
        case 1:
            deltaX = 1;
            break;
        case 2:
            deltaY = -1;
            break;
        case 3:
            deltaX = -1;
            break;
        case 4:
            deltaX = -1;
            deltaY = 1;
            break;
        case 5:
            deltaX = 1;
            deltaY = 1;
            break;
        case 6:
            deltaX = 1;
            deltaY = -1;
            break;
        case 7:
            deltaX = -1;
            deltaY = -1;
            break;
        default:
            break;
        }

        location.setPoint(location.getX() + deltaX * steps, location.getY() + deltaY * steps);  // update the character's location based on the change in x and y coordinates
    }

    Point2D getLocation() {   // method to retrieve the character's current location
        return location;
    }

    bool isNPC() { return npc; }   // method to determine whether the character is an NPC

    virtual void autoMove() = 0;   // virtual method to be implemented in derived classes, used to move the character automatically

};

class Prey : Character {

private:

    const int maxRange = 1;  // private member variable to store the maximum range that the Prey can move in a single turn

public:

    Prey(const std::string& name, const Point2D& location, bool npcFlag = 0) : Character(name, location, npcFlag) {   }  // constructor for the Prey class which calls the base class constructor

    int askDirection() {   // method to ask the user for a direction to move in

        int direction(0);
        cout << "Куда пойти?" << endl;
        cout << "0 - вверх, 1 - вправо, 2 - вниз, 3 - влево," << endl;
        cout << "4 - вверх-влево, 5 - вверх-вправо, 6 - вниз-вправо, 7 - вниз-влево" << endl;
        cin >> direction;
    }

    void autoMove() override {
        int direction = 0;
        int range = 0;
        if (isNPC()) {
            direction = rand() % 4;
            range = rand() % 5 + 1;
        }
        else {
            direction = askDirection();
            range = askRange();
        }
        moveTo(direction, range);
    }  // if the Prey is an NPC, choose a random direction to move in
}