#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "Point2D.h"
#include "Characters.h"

class Prey;
class Predator;
class Arena;

using namespace std;

ostream& operator<<(ostream& out, Predator& p) {
    out << "Èìÿ õèùíèêà - " << p.getName() << "\nÊîîðäèíàòû õèùíèêà - " << p.getLocation() << endl;
    return out;
}

//ostream& operator<<(ostream& out, const Arena& a) {
//    cout << "\033[2J\033[1;1H";
//    cout << "   ";
//    for (int i = 0; i < a.w; i++) cout << i + 1 << " ";
//    cout << "\n  ";
//    for (int i = 0; i < a.w + 1; i++) cout << "--";
//    cout << "\n";
//    for (int i = 0; i < a.l; i++) {
//        if ((i + 1) / 10 == 0) cout << i + 1 << " |";
//        else cout << i + 1 << "|";
//        if (a.prey->location.y == i + 1 && a.predator->location.y == i + 1) {
//            if (a.prey->location.x > a.predator->location.x) {
//                for (int j = 1; j < a.predator->location.x; j++) {
//                    cout << "  ";
//                }
//                cout << "Õ ";
//                for (int j = a.predator->location.x + 1; j < a.prey->location.x; j++) {
//                    cout << "  ";
//                }
//                cout << "Æ ";
//                for (int j = a.prey->location.x + 1; j <= a.w; j++) {
//                    cout << "  ";
//                }
//            }
//            else if (a.predator->location.x > a.prey->location.x) {
//                for (int j = 1; j < a.prey->location.x; j++) {
//                    cout << "  ";
//                }
//                cout << "Æ ";
//                for (int j = a.prey->location.x + 1; j < a.predator->location.x; j++) {
//                    cout << "  ";
//                }
//                cout << "Õ ";
//                for (int j = a.predator->location.x + 1; j <= a.w; j++) {
//                    cout << "  ";
//                }
//            }
//            else if (a.predator->location.x == a.prey->location.x) {
//                for (int j = 1; j < a.predator->location.x; j++) cout << "  ";
//                cout << "Õ ";
//                for (int j = a.predator->location.x; j < a.w; j++) cout << "  ";
//            }
//        }
//        else if (a.prey->location.y == i + 1) {
//            for (int j = 1; j < a.prey->location.x; j++) cout << "  ";
//            cout << "Æ ";
//            for (int j = a.prey->location.x; j < a.w; j++) cout << "  ";
//        }
//        else if (a.predator->location.y == i + 1) {
//            for (int j = 1; j < a.predator->location.x; j++) cout << "  ";
//            cout << "Õ ";
//            for (int j = a.predator->location.x; j < a.w; j++) cout << "  ";
//        }
//        else if (a.prey->location.y != i + 1 && a.predator->location.y != i + 1) {
//            for (int j = 0; j < a.w; j++) cout << "  ";
//        }
//        cout << "|\n";
//    }
//    cout << "  ";
//    for (int i = 0; i < a.w + 1; i++) cout << "--";
//    cout << "\n";
//    return out;
//}


bool check(Prey& prey, Predator& predator) {

    if (prey.getX() == predator.getX() && abs(prey.getY() - predator.getY()) <= 5) {
        return 1;
    }
    else if (prey.getY() == predator.getY() && abs(prey.getX() - predator.getX() <= 5) )
    {
        return 1;
    }
    else return 0;
}


bool check1(Prey& prey, Predator& predator) {
    if ((prey.getX() == predator.getX()) && (prey.getY() == predator.getY())) return 1;
    else return 0;
}