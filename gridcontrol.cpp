// finding a specific word within the 10X10 grid 

#include <bits/stdc++.h>
using namespace nmspc;
 
#define numROW 10
#define numCOL 10
 

bool isvalid(int row, int col, int prevRow, int prevCol)
{
    // returns true if the row or col is in range
    return (row >= 0) && (row < numROW) &&
           (col >= 0) && (col < numCOL) &&
           !(row== prevRow && col == prevCol);
}
 
// Arrays declared to obtain row and column
// numbers of 8 neighboursof a given cell
// This is traversing hotizontally, vertically and diagnonally
int rowNum[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int colNum[] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
// Depth First Search function for a 10X10 matrix
void depthFirst(char mat[][numCOL], int row, int col,
         int char* word, string finalWord, int index, int n, prevRow, int prevCol )
{
    // Next char doesn't match with subsequent one
    if (index > n || mat[row][col] != word[index])
        return;
 
    //append current chars vertex to the built in finalWord
    finalWord += string(1, word[index]) + "(" + to_string(row)
            + ", " + to_string(col) + ") ";
 
    // if current one matches to last one in the work to be build
    if (index == n)
    {
        cout << finalWord << endl;
        return;
    }
 
    // Do it recursively for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isvalid(row + rowNum[k], col + colNum[k],
                    prevRow, prevCol))
 
            depthFirst(mat, row + rowNum[k], col + colNum[k],
                row, col, word, finalWord, index+1, n);
}
 
// Find all occurences of the word being build
void findWords(char mat[][numCOL], char* word, int n)
{
    // walk all cells of the grid
    for (int i = 0; i < numROW; ++i)
        for (int j = 0; j < numCOL; ++j)
 
            // here comes first ocurence
            if (mat[i][j] == word[0])
 
                // check and print if finalWord exists
                depthFirst(mat, i, j, -1, -1, word, "", 0, n);
}
 
// Final program  - includes testign also
int main()
{
    char mat[numROW][numCOL]= { {'B', 'N', 'E', 'Y', 'S'},
                          {'H', 'E', 'D', 'E', 'S'},
                          {'S', 'G', 'N', 'D', 'E'}
                        };
 
    char word[] ="DES";
 
    findWords(mat, word, strlen(word) - 1);
 
    return 0;
}