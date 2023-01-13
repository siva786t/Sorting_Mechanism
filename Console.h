//
// Created by Sivasubramani on 18/12/22.
//

#ifndef SORTING_CONSOLE_H
#define SORTING_CONSOLE_H

#include "CommonFiles.h"
class Console {
    static Console *instance;
    // Private constructor so that no objects can be created.
    Console() {};
public:
    static Console *getInstance() {
        if (!instance)
            instance = new Console;
        return instance;
    }

    void printValue(vector<int> A,string type);
};


#endif //SORTING_CONSOLE_H
