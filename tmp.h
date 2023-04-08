#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "Point2D.h"

class Prey;
class Predator;
class Arena;

using namespace std;


class Character {

private:

    string name;
    string role;
    Point2D location;

public:

    Character(const std::string& name, const Point2D& location) 
        : name(name), location(location), role("no role") {   }

    void MoveTo(int x, int y) {
        location.setPoint(x, y);
    }

    Point2D getLocation() {
        return location;
    }

    //ostream& operator<<(ostream& out, const Character& p) {
    //    out << "��� ��������� - " << p.name << "���������� ��������� - " << p.location << endl;
    //    return out;
    //}
  
};



class Prey : Character {
    friend ostream& operator<<(ostream&, const Arena&);
private:
    friend Predator;
    friend class Arena;
    
    
    std::string name;
    Point2D location;

public:
    Prey(const std::string& name, const Point2D& location) : name(name), location(location) {   }



    void AutoMove(const Arena&, int z);

    friend ostream& operator<<(ostream& out, const Prey&);
    friend bool check(const Prey& prey, const Predator& predator);
    friend bool check1(const Prey& prey, const Predator& predator);

};


class Predator {
private:
    friend Prey;
    friend class Arena;
    friend ostream& operator<<(ostream&, const Arena&);
    std::string name;
    Point2D location;

public:
    Predator(const std::string& name, const Point2D& location) : name(name), location(location) {   }

    void MoveTo(int x, int y) {
        location.setPoint(x, y);
    }
    void AutoMove(const Arena&, int z);
    friend ostream& operator<<(ostream&, const Predator&);
    friend bool check(const Prey& prey, const Predator& predator);
    friend bool check1(const Prey& prey, const Predator& predator);
};
ostream& operator<<(ostream& out, const Predator& p) {
    out << "��� ������� - " << p.name << "\n���������� ������� - " << p.location << endl;
    return out;
}




class Arena {
    int l, w;
    Prey* prey;
    Predator* predator;
public:
    Arena(int w, int l, Prey* prey, Predator* predator) {
        this->l = l;
        this->w = w;
        this->prey = prey;
        this->predator = predator;
    }
    friend ostream& operator<<(ostream&, const Arena&);
    friend void Prey::AutoMove(const Arena& a, int z);
    friend void Predator::AutoMove(const Arena& ar, int z);

};

ostream& operator<<(ostream& out, const Arena& a) {
    cout << "\033[2J\033[1;1H";
    cout << "   ";
    for (int i = 0; i < a.w; i++) cout << i + 1 << " ";
    cout << "\n  ";
    for (int i = 0; i < a.w + 1; i++) cout << "--";
    cout << "\n";
    for (int i = 0; i < a.l; i++) {
        if ((i + 1) / 10 == 0) cout << i + 1 << " |";
        else cout << i + 1 << "|";
        if (a.prey->location.y == i + 1 && a.predator->location.y == i + 1) {
            if (a.prey->location.x > a.predator->location.x) {
                for (int j = 1; j < a.predator->location.x; j++) {
                    cout << "  ";
                }
                cout << "� ";
                for (int j = a.predator->location.x + 1; j < a.prey->location.x; j++) {
                    cout << "  ";
                }
                cout << "� ";
                for (int j = a.prey->location.x + 1; j <= a.w; j++) {
                    cout << "  ";
                }
            }
            else if (a.predator->location.x > a.prey->location.x) {
                for (int j = 1; j < a.prey->location.x; j++) {
                    cout << "  ";
                }
                cout << "� ";
                for (int j = a.prey->location.x + 1; j < a.predator->location.x; j++) {
                    cout << "  ";
                }
                cout << "� ";
                for (int j = a.predator->location.x + 1; j <= a.w; j++) {
                    cout << "  ";
                }
            }
            else if (a.predator->location.x == a.prey->location.x) {
                for (int j = 1; j < a.predator->location.x; j++) cout << "  ";
                cout << "� ";
                for (int j = a.predator->location.x; j < a.w; j++) cout << "  ";
            }
        }
        else if (a.prey->location.y == i + 1) {
            for (int j = 1; j < a.prey->location.x; j++) cout << "  ";
            cout << "� ";
            for (int j = a.prey->location.x; j < a.w; j++) cout << "  ";
        }
        else if (a.predator->location.y == i + 1) {
            for (int j = 1; j < a.predator->location.x; j++) cout << "  ";
            cout << "� ";
            for (int j = a.predator->location.x; j < a.w; j++) cout << "  ";
        }
        else if (a.prey->location.y != i + 1 && a.predator->location.y != i + 1) {
            for (int j = 0; j < a.w; j++) cout << "  ";
        }
        cout << "|\n";
    }
    cout << "  ";
    for (int i = 0; i < a.w + 1; i++) cout << "--";
    cout << "\n";
    return out;
}

void Prey::AutoMove(const Arena& a, int z) {
    int q;
    if (z == 1) {
        q = rand() % 8;
    }
    else {
        cout << "���� ����?\n0-�����-����� 1-����� 2-�����-������ 3-����� 4-������ 5-����-����� 6-���� 7-����-������" << endl;
        cin >> q;
    }
    switch (q) {
    case 0:
        if (location.x != 1 && location.y != 1) {
            location.x -= 1;
            location.y -= 1;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 1:
        if (location.y != 1) {
            location.y -= 1;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 2:
        if (location.x != a.w && location.y != 1) {
            location.x += 1;
            location.y -= 1;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 3:
        if (location.x != 1) {
            location.x -= 1;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 4:
        if (location.x != a.w) {
            location.x += 1;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 5:
        if (location.x != 1 && location.y != a.l) {
            location.x -= 1;
            location.y += 1;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 6:
        if (location.y != a.l) {
            location.y += 1;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 7:
        if (location.x != a.w && location.y != a.l) {
            location.x += 1;
            location.y += 1;
        }
        else cout << "����� �� �������" << endl;
        break;
    default:
        break;
    }
}

void Predator::AutoMove(const Arena& ar, int z) {
    int q;
    int a;
    if (z == 0) {
        q = rand() % 4;
        a = rand() % 5 + 1;
    }
    else {
        int s = 0;
        cout << "���� ����?\n0-����� 1-������ 2-���� 3-�����" << endl;
        cin >> q;

        do {
            cout << "�� �������? (1-5)" << endl;
            cin >> a;
            if (1 <= a && a <= 5) s = 1;
        } while (s != 1);
    }

    switch (q) {
    case 0:
        if (location.y >= (a)) {
            location.y -= a;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 1:
        if (location.x <= (ar.w - a)) {
            location.x += a;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 2:
        if (location.y <= (ar.l - a)) {
            location.y += a;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 3:
        if (location.x >= (a)) {
            location.x -= a;
        }
        else cout << "����� �� �������" << endl;
        break;
    }
}

bool check(const Prey& prey, const Predator& predator) {
    if (prey.location.x == predator.location.x && abs(prey.location.y - predator.location.y) <= 5) {
        return 1;
    }
    else if (prey.location.y == predator.location.y && abs(prey.location.x - predator.location.x) <= 5) {
        return 1;
    }
    else return 0;
}
bool check1(const Prey& prey, const Predator& predator) {
    if ((prey.location.x == predator.location.x) && (prey.location.y == predator.location.y)) return 1;
    else return 0;
}