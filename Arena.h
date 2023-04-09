#pragma once

#include <array>
#include "Characters.h"


class Arena {

    int length, width;
    Prey* prey;
    Predator* predator;

    char** field;

public:

    Arena(int w, int l, Prey* prey, Predator* predator) {
        //TODO: Проверка диапазона l w от (1 до 99)       
        this->length = l;

        w = w * 2;

        this->width = w;
        this->prey = prey;
        this->predator = predator;
        field = new char* [l];

        for (int i = 0; i < l; i++)
        {
            field[i] = new char[w];

            for (int j = 0; j < w; j++)
            {
                field[i][j] = ' ';
            }
        }


        for (int i = l - 1; i >= 0; i--) {

            if (l - i > 9) {
                int tmp = ((l - i) / 10);
                field[i][0] = ((l - i) / 10) + '0';
                field[i][1] = ((l - i) % 10) + '0';
            }
            else field[i][1] = l - i + '0';

            field[i][2] = '|';
        }

        for (int i = 0; i < w; i++)
        {
            int cell_num = 1 + (i / 2);

            if (cell_num > 9) {

                if ((i + 1) % 2 == 0) {
                    field[l - 1][i] = (cell_num % 10) + '0';
                }
                else field[l - 1][i] = (cell_num / 10) + '0';

            }
            else {
                if ((i + 1) % 2 == 0) {
                    field[l - 1][i] = cell_num + '0';
                }
                else field[l - 1][i] = ' ';
            }

        }

        for (int i = 3; i < w; i++)
        {
            field[l - 2][i] = '_';
        }

    }

    ~Arena() {
        delete[] field;
    }

    friend ostream& operator<<(ostream&, const Arena&);

};



ostream& operator<<(ostream& out, const Arena& a) {

    int preyX = (a.prey->getLocation().getX() * 2) + 3;

    int preyY = a.prey->getLocation().getY() + 2;

    a.field[a.length - preyY][preyX] = '^';

    for (int i = 0; i < a.length; i++) {
        for (int j = 0; j < a.width; j++) {
            cout << a.field[i][j];
        }
        cout << "\n";
    }

    int aaqaa = 0;


    return out;
}
