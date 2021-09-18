/*#include <iostream>
#include "Array.h"

namespace Budapesht {

	void put(Array& array, Element& element) {
		bool isAdded = false;
		Element* el = nullptr;
		if (array.curSize == array.size)
			resize(array);
		for (int i = 0; i < array.curSize; i++) {

			if(!isAdded) {

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
			if(isAdded) {
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
		delete array;
		array = nullptr;
	}

}*/