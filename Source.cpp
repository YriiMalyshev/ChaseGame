#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>

#include "Characters.h"
#include "Arena.h"

using namespace std;


int main() {
    system("chcp 65001");

    srand(time(NULL));


    Prey prey("prey", Point2D(3, 10), true);
    Predator predator("predator", Point2D(1, 1), false);

    Arena arena(20, 20, &prey, &predator);

    cout << arena;


    return 0;
}