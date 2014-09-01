#include "matrix.h"
#include <time.h>
#include <stdlib.h>

void matrix::init()
{
    for( int i=0; i<ROW; i++ )
        for ( int j=0; j<COL; j++ )
            a[i][j] = 0;
}
// currently only could generate tile with value '2'
bool matrix::random_increase()
{
    int m=0, n=0, k=0, empty_count=0;
    int tmp[ROW*COL] = {0};
    srand( (unsigned)time( NULL ) );
    // loop to find empty tiles.
    for( int i=0; i<ROW; i++ )
        for ( int j=0; j<COL; j++ )
            if ( a[i][j] == 0 )
                tmp[empty_count++] = ROW*i + j;

    if ( empty_count > 0 )
    {
        srand( (unsigned)time( NULL ) );
        k = rand() % empty_count;
        m = tmp[k] / COL;
        n = tmp[k] % COL;
        a[m][n] = (rand()%10)>6 ? 4 : 2;
        return true;
    }
    else
        return false;
}
void matrix::print()
{
    for( int i=0; i<ROW; i++ )
    {
        for ( int j=0; j<COL; j++ )
            cout << a[i][j] << "  ";
        cout << endl;
    }
    cout << endl;
}

bool matrix::notFull()
{
    for( int i=0; i<ROW; i++ )
        for ( int j=0; j<COL; j++ )
            if( a[i][j] == 0 )
                return true;

    return false;
}


bool matrix::up()
{
    bool couldMove = false;
    // do conbination, pay attention to empty tiles !
    for( int j=0; j<COL; j++ )
    {
        for ( int i=0; i<ROW; i++ )
        {
            if ( a[i][j] == 0 )
            {
                couldMove = true;
                int tmp = i+1;
                while ( tmp<ROW )
                {
                    if ( a[tmp][j] != 0 ) // find non-empty tile !
                    {
                        couldMove = true;
                        break;
                    }
                    else
                        tmp++;
                }
                continue;
            }
            else
            {
                int tmp = i+1;
                while ( tmp<ROW )
                {
                    if ( a[tmp][j] == 0 )
                        tmp++;
                    else if ( a[i][j] == a[tmp][j] )
                    {
                        a[i][j] <<= 1;
                        a[tmp][j] = 0;
                        couldMove = true;
                        break;
                    }
                    else
                        break;
                }
            }
        }
    }
    // do move.
    if ( couldMove )
    {
        for( int j=0; j<COL; j++ )
        {
            for ( int i=0; i<ROW; i++ )
            {
                if ( a[i][j] != 0 )
                {
                    continue;
                }
                else
                {
                    int tmp = i+1;
                    while ( tmp<ROW )
                    {
                        if ( a[tmp][j] != 0 ) // find non-empty tile !
                        {
                            a[i][j] = a[tmp][j];
                            a[tmp][j] = 0;
                            break;
                        }
                        else
                            tmp++;
                    }
                }
            }
        }
    }

    return couldMove;
}

bool matrix::down()
{
    bool couldMove = false;
    // do conbination, pay attention to empty tiles !
    for( int j=0; j<COL; j++ )
    {
        for ( int i=ROW-1; i>=0; i-- )
        {
            if ( a[i][j] == 0 )
            {
                couldMove = true;
                int tmp = i-1;
                while ( tmp>=0 )
                {
                    if ( a[tmp][j] != 0 ) // find non-empty tile !
                    {
                        couldMove = true;
                        break;
                    }
                    else
                        tmp--;
                }
                continue;
            }
            else
            {
                int tmp = i-1;
                while ( tmp>=0 )
                {
                    if ( a[tmp][j] == 0 )
                        tmp--;
                    else if ( a[i][j] == a[tmp][j] )
                    {
                        a[i][j] <<= 1;
                        a[tmp][j] = 0;
                        couldMove = true;
                        break;
                    }
                    else
                        break;
                }
            }
        }
    }
    // do move.
    if ( couldMove )
    {
        for( int j=0; j<COL; j++ )
        {
            for ( int i=ROW-1; i>=0; i-- )
            {
                if ( a[i][j] != 0 )
                {
                    continue;
                }
                else
                {
                    int tmp = i-1;
                    while ( tmp>=0 )
                    {
                        if ( a[tmp][j] != 0 ) // find non-empty tile !
                        {
                            a[i][j] = a[tmp][j];
                            a[tmp][j] = 0;
                            break;
                        }
                        else
                            tmp--;
                    }
                }
            }
        }
    }

    return couldMove;
}

bool matrix::left()
{
    bool couldMove = false;
    // do conbination, pay attention to empty tiles !
    for( int i=0; i<ROW; i++ )
    {
        for ( int j=0; j<COL; j++ )
        {
            if ( a[i][j] == 0 )
            {
                couldMove = true;
                int tmp = j+1;
                while ( tmp<COL )
                {
                    if ( a[i][tmp] != 0 ) // find non-empty tile !
                    {
                        couldMove = true;
                        break;
                    }
                    else
                        tmp++;
                }
                continue;
            }
            else
            {
                int tmp = j+1;
                while ( tmp<COL )
                {
                    if ( a[i][tmp] == 0 )
                        tmp++;
                    else if ( a[i][j] == a[i][tmp] )
                    {
                        a[i][j] <<= 1;
                        a[i][tmp] = 0;
                        couldMove = true;
                        break;
                    }
                    else
                        break;
                }
            }
        }
    }
    // do move.
    if ( couldMove )
    {
        for( int i=0; i<ROW; i++ )
        {
            for ( int j=0; j<COL; j++ )
            {
                if ( a[i][j] != 0 )
                {
                    continue;
                }
                else
                {
                    int tmp = j+1;
                    while ( tmp<COL )
                    {
                        if ( a[i][tmp] != 0 ) // find non-empty tile !
                        {
                            a[i][j] = a[i][tmp];
                            a[i][tmp] = 0;
                            break;
                        }
                        else
                            tmp++;
                    }
                }
            }
        }
    }

    return couldMove;
}

bool matrix::right()
{
    bool couldMove = false;
    // do conbination, pay attention to empty tiles !
    for( int i=0; i<ROW; i++ )
    {
        for ( int j=COL-1; j>=0; j-- )
        {
            if ( a[i][j] == 0 )
            {
                couldMove = true;
                int tmp = j-1;
                while ( tmp>=0 )
                {
                    if ( a[i][tmp] != 0 ) // find non-empty tile !
                    {
                        couldMove = true;
                        break;
                    }
                    else
                        tmp--;
                }
                continue;
            }
            else
            {
                int tmp = j-1;
                while ( tmp>=0 )
                {
                    if ( a[i][tmp] == 0 )
                        tmp--;
                    else if ( a[i][j] == a[i][tmp] )
                    {
                        a[i][j] <<= 1;
                        a[i][tmp] = 0;
                        couldMove = true;
                        break;
                    }
                    else
                        break;
                }
            }
        }
    }
    // do move.
    if ( couldMove )
    {
        for( int i=0; i<ROW; i++ )
        {
            for ( int j=COL-1; j>=0; j-- )
            {
                if ( a[i][j] != 0 )
                {
                    continue;
                }
                else
                {
                    int tmp = j-1;
                    while ( tmp>=0 )
                    {
                        if ( a[i][tmp] != 0 ) // find non-empty tile !
                        {
                            a[i][j] = a[i][tmp];
                            a[i][tmp] = 0;
                            break;
                        }
                        else
                            tmp--;
                    }
                }
            }
        }
    }

    return couldMove;
}

int main()
{
    matrix mtx_2048;

    mtx_2048.init();
    mtx_2048.print();
    cout << endl;

    string input;

    while ( mtx_2048.random_increase() )
    {
        mtx_2048.print();
        cout<<" Operation? input string - w, s, a, d : ";
        cin>>input;

        if( input == "s" && mtx_2048.down() )
            continue;
        else if (input == "d" && mtx_2048.right() )
            continue;
        else if (input == "w" && mtx_2048.up() )
            continue;
        else if( input == "a" && mtx_2048.left() )
            continue;
        else {
            cout << " Game Over! " << endl;
            break;
        }
    }
    return 0;
#if 0
        if ( mtx_2048.down() )
        {
            mtx_2048.print();
            continue;
        }
        else if (mtx_2048.right() )
        {
            mtx_2048.print();
            continue;
        }
        else if (mtx_2048.up() )
        {
            mtx_2048.print();
            continue;
        }
        else if (mtx_2048.left() )
        {
            mtx_2048.print();
            continue;
        }
        else
            break;
    }

    cout<< "Game Over!" <<endl;
    return 0;
#endif // 0

}
