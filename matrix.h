#ifndef MATIRX_H_INCLUDED
#define MATIRX_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define COL 4
#define ROW 4

class matrix {
    public:
        void   init();
        bool   random_increase();
        void   print();
        bool   notFull();

        bool   up();
        bool   down();
        bool   left();
        bool   right();

    private:
        int a[ROW][COL];
        int score;
};


#endif // MATIRX_H_INCLUDED
