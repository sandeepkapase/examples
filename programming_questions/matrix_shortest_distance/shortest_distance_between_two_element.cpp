#include <queue>
#include <iostream>

using namespace std;

inline bool checkUpdateVisit(char *mat, int *visitMap, int i, int j, int m, int n, queue<pair <int,int>> *Q)
{
    if (i < 0 || i >= m || j < 0 || j >= n || *(mat+(i*n)+j) == '0' ||  *(visitMap+(n*i)+j) != 0)
        return false;

    Q->push(pair<int,int>(i, j));
    *(visitMap+(i*n)+j) = 1;
    return true;
}

int main (void)
{
    int distance=0,m,n,i,j,sourceX,sourceY,destX, destY,*visitMap;
    queue<pair <int,int>>first,second;
    queue<pair <int,int>> *Q1=&first, *Q2=&second;
    pair<int,int> element;
    char *mat;

    cin >> m >> n; // ROWS, COLUMNS
    mat = new char[m*n];
    visitMap = new int[m*n]();

    for(i=0; i<m; i++)
        for(j=0;j<n;j++)
            cin >> (mat+(n*i)+j); // matrix input

    cin >> sourceX >> sourceY >> destX >> destY; // source/destination coordinate

    checkUpdateVisit(mat, visitMap, sourceX, sourceY, m, n, Q1);

    while (! Q1->empty() || ! Q2->empty()) {
        while(! Q1->empty() ) {
            element = Q1->front();
            Q1->pop();
            if (element.first == destX && element.second == destY) {
                cout << distance << endl;
                return EXIT_SUCCESS;
            }
            checkUpdateVisit(mat, visitMap, element.first-1, element.second, m, n, Q2);//TOP
            checkUpdateVisit(mat, visitMap, element.first+1, element.second, m, n, Q2);//BOTTOM
            checkUpdateVisit(mat, visitMap, element.first, element.second-1, m, n, Q2);//LEFT
            checkUpdateVisit(mat, visitMap, element.first, element.second-1, m, n, Q2);//RIGHT
        }
        distance++;
        swap(Q1,Q2);
    }
    cout << "No path to destination";
    return EXIT_SUCCESS;
}
