#include "Characters.h"

using namespace std;

// Конструктор класса Character
Character::Character(const string& name, const Point2D& location, bool npcFlag)
    : name(name), location(location), npc(npcFlag) {}

// Метод для перемещения персонажа в указанную точку
void Character::moveTo(Point2D point) {
    location = point;
}

// Метод для перемещения персонажа в направлении direction на указанное количество шагов steps
void Character::moveTo(int direction, int steps) {
    int deltaX = 0, deltaY = 0;

    // Определяем изменение координат в зависимости от направления движения
    switch (direction) {
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

    // Обновляем координаты персонажа
    location.setPoint(location.getX() + deltaX * steps, location.getY() + deltaY * steps);
}

// Метод для получения текущей позиции персонажа
Point2D Character::getLocation() {
    return location;
}

// Метод для проверки, является ли персонаж NPC
bool Character::isNPC() {
    return npc;
}


// Конструктор класса Prey
Prey::Prey(const string& name, const Point2D& location, bool npcFlag)
    : Character(name, location, npcFlag) {}

// Метод для запроса направления у пользователя
int Prey::askDirection() {
    do {
        int direction = 0;
        cout << "Куда вы хотите пойти? \n";
        cout << "0 - вверх, 1 - вправо, 2 - вниз, 3 - влево, \n";
        cout << "4 - вверх-влево, 5 - вверх-вправо, 6 - вниз-вправо, 7 - вниз-влево \n";
        cin >> direction;

        if (direction <= 7 && direction >= 0) {
            return direction;
        }
        else {
            cout << "Неверное направление, попробуйте еще раз \n" << endl;
        }
    } while (true);
}


void Prey::autoMove() {

    int direction = 0;

    if (isNPC()) {
        direction = rand() % 8;
    }
    else {
        direction = askDirection();
    }

    moveTo(direction, maxRange);
}