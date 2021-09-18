#include <iostream>
#include "Matrix.h"

using namespace Batrudinov;

void menu(Matrix& matrix);

int main()
{
    Matrix* matrix = newMatrix();

    menu(*matrix);

    /*    out(matrix);
    std::cout << std::endl;
    Line* vector = getVector(matrix, filter1);
    //Line* vector = getVector(matrix, filter2);
    outVector(vector, matrix->m);
    delete[] vector->elements;
    delete vector;
    free(matrix);
*/
    free(matrix);
    //menu(*matrix);
    return 0;
}


void menu(Matrix& matrix) {
    bool isOpen = true;
    do {
        std::cout << "Menu:\n\t1. ADD ELEMENT\n\t2. DELETE ELEMENT\n\t3. CREATE VECTOR\n\t4. PRINT MATRIX\n\t5. EXIT" << std::endl;
        int choice = -1;
        while (true) {
            std::cout << "CHOICE:" << std::endl;
            if (!getNum(choice))
                std::cout << "Try again!" << std::endl;
            else
                break;
        }
        int x;
        int y;
        int value;
        Line* vector;
        switch (choice) {
        case 1:
            while (true) {
                std::cout << "x:" << std::endl;
                if (!getNum(x))
                    std::cout << "Try again!" << std::endl;
                else
                    break;
            }
            while (true) {
                std::cout << "y:" << std::endl;
                if (!getNum(y))
                    std::cout << "Try again!" << std::endl;
                else
                    break;
            }
            while (true) {
                std::cout << "value:" << std::endl;
                if (!getNum(value))
                    std::cout << "Try again!" << std::endl;
                else
                    break;
            }
            if (x >= 0 && x < matrix.n && y >= 0 && y < matrix.m) {
                put(matrix, x, y, value);
            }
            else {
                std::cerr << "ERROR!" << std::endl;
            }
            break;
        case 2:
            while (true) {
                std::cout << "x:" << std::endl;
                if (!getNum(x))
                    std::cout << "Try again!" << std::endl;
                else
                    break;
            }
            while (true) {
                std::cout << "y:" << std::endl;
                if (!getNum(y))
                    std::cout << "Try again!" << std::endl;
                else
                    break;
            }
            if (x >= 0 && x < matrix.n && y >= 0 && y < matrix.m) {
                remove(matrix.lines[x], y);
            }
            else {
                std::cerr << "ERROR!" << std::endl;
            }
            break;
        case 3:
            vector = getVector(&matrix, filter1);
            outVector(vector, matrix.m);
            delete vector;
            break;
        case 4:
            out(&matrix);
            break;
        case 5:
            isOpen = false;
            break;
        default:
            break;
        }
    } while (isOpen);
}