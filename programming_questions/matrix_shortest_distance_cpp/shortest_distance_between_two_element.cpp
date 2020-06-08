#include <bits/stdc++.h>
#include <boost/dynamic_bitset.hpp>
#include <queue>
#include <iostream>

using namespace std;
class matixMinDistCalculator {
    private:
        int distance=0,rows,columns,sourceX,sourceY,destX, destY;
        boost::dynamic_bitset<> visitMap;
        queue<pair <int,int>>first,second;
        queue<pair <int,int>> *Q1=&first, *Q2=&second;
        pair<int,int> element;
        char *matrix;
        bool found;

        bool checkUpdateVisit(int i, int j, queue<pair <int,int>> *Q) {
            if (i < 0 || i >= rows || j < 0 || j >= columns || *(matrix+(i*columns)+j) == '0' ||  visitMap[columns*i+j] != 0)
                return false;
            Q->push(pair<int,int>(i, j));
            visitMap[i*columns+j].flip();
            return true;
        }

    public:
        matixMinDistCalculator(char *matrix, int rows, int columns, int sourceX, int sourceY,  int destX, int destY):
            rows(rows),  columns(columns), sourceX(sourceX), sourceY(sourceY), destX(destX), destY(destY),matrix(matrix) {
                visitMap.resize(rows*columns);
                found = false;
                distance = -1;

            }

        int findMinDistance(void) {
            checkUpdateVisit( sourceX, sourceY, Q1);
            if (found) return distance;
            while (! Q1->empty() || ! Q2->empty()) {
                while(! Q1->empty() ) {
                    element = Q1->front();
                    Q1->pop();
                    if (element.first == destX && element.second == destY) {
                        found = true;
                        return ++distance;
                    }
                    checkUpdateVisit(element.first-1, element.second, Q2);//TOP
                    checkUpdateVisit(element.first+1, element.second, Q2);//BOTTOM
                    checkUpdateVisit(element.first, element.second-1, Q2);//LEFT
                    checkUpdateVisit(element.first, element.second-1, Q2);//RIGHT
                }
                distance++;
                swap(Q1,Q2);
            }
            if (found)
                return distance;
            else
                return -1;
        }

};


int main (void)
{
    int rows,columns,i,j,sourceX,sourceY,destX,destY;
    char *matrix;

    cin >> rows >> columns; // ROWS, COLUMNS
    matrix = new char[rows*columns];

    for(i=0; i<rows; i++)
        for(j=0;j<columns;j++)
            cin >> (matrix+(columns*i)+j); // matrixrix input

    cin >> sourceX >> sourceY >> destX >> destY; // source/destination coordinate
    matixMinDistCalculator mc(matrix, rows, columns, sourceX, sourceY, destX, destY);
    cout << mc.findMinDistance();
    return EXIT_SUCCESS;
}
