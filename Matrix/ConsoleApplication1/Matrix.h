namespace Batrudinov {

	struct Element {
		int value;
		int place;
	};

	struct Array {
		Element** elements;
		int size;
		int curSize;
	};

	struct Line {
		int* elements;
	};
	
	struct Matrix {
		//ğàçìåğíîñòü
		int n;
		int m;
		int maxInt;
		Array* lines;
	};

	template <class T>
	bool getNum(T& a) {
		std::cin >> a;
		if (!std::cin.good()) {
			std::cin.clear();
			while (std::cin.get() != '\n');
			return false;
		}
		return true;
	}

	inline bool filter1(int a) {
		return abs(a) >= 10;
	}

	inline bool filter2(int a) {
		return a % 2 == 0;
	}

	Matrix* newMatrix();
	bool put(Matrix& matrix, int x, int y, int value);
	void out(Matrix*);
	Line* getVector(Matrix*, bool(*f)(int));
	void free(Matrix*&);
	void outVector(Line*, int);

	//ÏÎ ÈÄÅÅ İÒÎ ÕĞÅÍÜ ÏÎËÍÀß

	inline Array* newArray(int size) {
		if (size <= 0)
			throw _invalid_parameter;
		Array* array = new Array;
		array->size = size;
		array->curSize = 0;
		array->elements = new Element * [size];
		return array;
	}

	inline void resize(Array& array) {
		array.size += 10;
		Element** newArr = new Element * [array.size];
		for (int i = 0; i < array.curSize; i++)
		{
			newArr[i] = array.elements[i];
		}
		delete[] array.elements;
		array.elements = newArr;
	}

	inline Element* newElement(int value, int place) {
		Element* element = new Element;
		element->place = place;
		element->value = value;
		return element;
	}

	void put(Array& array, Element& element);
	bool remove(Array& array, int place);
	void print(Array& array);
	void free(Array*& array);
}