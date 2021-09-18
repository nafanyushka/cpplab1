#include <iostream>
#include "Matrix.h"
using std::abs;

//using namespace Budapesht;
namespace Batrudinov {

	Matrix* newMatrix() {
		const char* errorMessage = "";
		Matrix* matrix = new Matrix;
		while (true) {
			std::cout << "Input m:" << std::endl;
			if (!getNum(matrix->m))
				std::cout << "Try again!" << std::endl;
			else
				break;
		}
		while (true) {
			std::cout << "Input n:" << std::endl;
			if (!getNum(matrix->n))
				std::cout << "Try again!" << std::endl;
			else
				break;
		}
		matrix->lines = new Array[matrix->m];
		for (int i = 0; i < matrix->m; i++) {
			matrix->lines[i] = *newArray(3);
		}
		return matrix;
	}

	void out(Matrix* matrix) {
		for (int i = 0; i < matrix->m; i++) {
			int seen = 0;
			Element* next;
			if (matrix->lines[i].curSize > 0)
				next = matrix->lines[i].elements[0];
			else
				next = nullptr;
			Element* element = *matrix->lines[i].elements;
			for (int j = 0; j < matrix->n; j++) {
				if (next == nullptr) {
					std::cout << 0 << '\t';
					continue;
				}
				if (next->place == j) {
					std::cout << next->value << '\t';
					seen++;
					if (seen == matrix->lines[i].curSize)
						next = nullptr;
					else next = matrix->lines[i].elements[seen];
				}
				else std::cout << 0 << '\t';
			}
			std::cout << std::endl;
		}
	}

	Line* getVector(Matrix* matrix, bool(*f)(int)) {
		Line* line = new Line;
		line->elements = new int[matrix->m];
		for (int i = 0; i < matrix->m; i++) {
			int a = 0;
			for (int j = 0; j < matrix->lines[i].curSize; j++) {
				if(f(matrix->lines[i].elements[j]->value))
					a += matrix->lines[i].elements[j]->value;
			}
			line->elements[i] = a;
		}
		return line;
	}
	void free(Matrix*& matrix) {
		for (int i = 0; i < matrix->m; i++) {
			Array* line = &matrix->lines[i];
			free(line);
			//matrix->lines++;
		}
		delete[] matrix->lines;
		delete matrix;
	}

	void outVector(Line* line, int m) {
		for (int i = 0; i < m; i++) {
			std::cout << line->elements[i] << '\t';
		}
		std::cout << std::endl;
	}

	bool put(Matrix& matrix, int x, int y, int value) {
		put(matrix.lines[x], *newElement(value, y));
		return true;
	}

	void put(Array& array, Element& element) {
		bool isAdded = false;
		Element* el = nullptr;
		if (array.curSize == array.size)
			resize(array);
		for (int i = 0; i < array.curSize; i++) {

			if (!isAdded) {

				if (array.elements[i]->place == element.place) {
					delete& (array.elements[i]);
					array.elements[i] = &element;
					return;
				}

				if (array.elements[i]->place > element.place) {
					el = array.elements[i];
					array.elements[i] = &element;
					isAdded = true;
				}

			}
			if (isAdded) {
				Element* helper = array.elements[i + 1];
				array.elements[i + 1] = el;
				el = helper;
			}
		}
		if (isAdded) {
			array.curSize++;
			return;
		}
		array.elements[array.curSize] = &element;
		std::cout << array.elements[array.curSize]->place << std::endl;
		array.curSize++;
	}

	bool remove(Array& array, int place) {
		bool isDeleted = false;
		for (int i = 0; i < array.curSize; i++) {
			if (isDeleted) {
				array.elements[i - 1] = array.elements[i];
			}
			else if (array.elements[i]->place == place) {
				delete array.elements[i];
				isDeleted = true;
			}
		}
		if (isDeleted)
			array.curSize--;
		return isDeleted;
	}

	void print(Array& array) {
		for (int i = 0; i < array.curSize; i++) {
			std::cout << array.elements[i]->place << ": " << array.elements[i]->value << " ";
		}
		std::cout << std::endl;
	}

	void free(Array*& array) {
		for (int i = 0; i < array->curSize; i++) {
			delete array->elements[i];
		}
		delete[] array->elements;
	}
}