#include "Arena.h"

Arena::Arena(int l, int w, Prey* prey, Predator* predator)
    : prey(prey), predator(predator), length(l), width(w)
{
    // Check if length and width are within (1, 99)
    if (length < 1 || length > 99 || width < 1 || width > 99) {
        throw std::invalid_argument("Invalid arena dimensions.");
    }

    // Define view dimensions
    int shift_l = 3;
    int shift_w = 4;
    int stretch_w = 2;
    view_length = length + shift_l;
    view_width = width * stretch_w + shift_w;

    // Create arena field
    field = new char* [view_length]();
    for (int i = 0; i < view_length; i++) {
        field[i] = new char[view_width]();
        for (int j = 0; j < view_width; j++) {
            field[i][j] = ' ';
        }
    }

    // Draw the borders and grid lines
    for (int j = 2; j < view_width; j++) {
        field[0][j] = '~';  // top border
        field[view_length - 2][j] = '~';  // bottom border

        // Draw the vertical grid lines
        int cell_num = (j / 2);
        if (j >= view_width - 2) continue;
        if (cell_num > 9) {
            if ((j + 1) % 2 == 0) {
                field[view_length - 1][j + 1] = (cell_num % 10) + '0';
            }
            else {
                field[view_length - 1][j + 1] = (cell_num / 10) + '0';
            }
        }
        else {
            if ((j + 1) % 2 == 0) {
                field[view_length - 1][j + 1] = cell_num + '0';
            }
            else {
                field[view_length - 1][j + 1] = ' ';
            }
        }
    }

    // Draw the horizontal grid lines
    for (int i = 1; i < view_length - 2; i++) {
        field[i][2] = '|';  // left border
        field[i][view_width - 1] = '|';  // right border

        // Draw the row numbers
        int y_coords = view_length - shift_l + 1;
        if (y_coords - i > 9) {
            field[i][0] = ((y_coords - i) / 10) + '0';
            field[i][1] = ((y_coords - i) % 10) + '0';
        }
        else {
            field[i][1] = y_coords - i + '0';
        }
    }
}

void Arena::clearStep() {
    // Получаем координаты добычи
    int preyX = (prey->getLocation().getX() * 2) + 2;
    int preyY = prey->getLocation().getY() + 2;

    // Очищаем след добычи
    field[view_length - preyY][preyX] = ' ';
    field[view_length - preyY][preyX - 1] = ' ';

    // Получаем координаты хищника
    int predX = (predator->getLocation().getX() * 2) + 2;
    int predY = predator->getLocation().getY() + 2;

    // Очищаем след хищника
    field[view_length - predY][predX] = ' ';
    field[view_length - predY][predX - 1] = ' ';
}

// Проверяет, не вышла ли добыча или хищник за границы поля
bool Arena::checkOverRun() {
    // Получаем координаты добычи
    int preyX = (prey->getLocation().getX() * 2) + 2;
    int preyY = prey->getLocation().getY() + 2;

    // Если добыча вышла за границы поля, возвращаем true
    if (preyX > width || preyX < 1 || preyY > length || preyY < 1) return true;

    // Получаем координаты хищника
    int predX = (predator->getLocation().getX() * 2) + 2;
    int predY = predator->getLocation().getY() + 2;

    // Если хищник вышел за границы поля, возвращаем true
    if (predX > width || predX < 1 || predY > length || predY < 1) return true;

    // Иначе возвращаем false
    return false;
}

// Деструктор класса Arena
Arena::~Arena() {
    // Освобождаем выделенную память для поля
    for (int i = 0; i < length; i++) {
        delete[] field[i];
    }
    delete[] field;
}

std::ostream& operator<<(std::ostream& out, const Arena& arena) {
    // Вычисляем координаты добычи и хищника на поле.
    int prey_x = (arena.prey->getLocation().getX() * 2) + 2;
    int prey_y = arena.prey->getLocation().getY() + 2;

    // Рисуем добычу на поле.
    arena.field[arena.view_length - prey_y][prey_x] = ')';
    arena.field[arena.view_length - prey_y][prey_x - 1] = '(';

    // Вычисляем координаты хищника на поле.
    int predator_x = (arena.predator->getLocation().getX() * 2) + 2;
    int predator_y = arena.predator->getLocation().getY() + 2;

    // Рисуем хищника на поле.
    arena.field[arena.view_length - predator_y][predator_x] = '*';
    arena.field[arena.view_length - predator_y][predator_x - 1] = '*';

    // Выводим поле в поток.
    for (int y = 0; y < arena.view_length; y++) {
        for (int x = 0; x < arena.view_width; x++) {
            std::cout << arena.field[y][x];
        }
        std::cout << "\n";
    }

    // Возвращаем поток.
    return out;
}
