

#include <iostream>

class darray{

public:

	darray() {}

	darray(int size) {
		this->size = size;
		float val = 0.0f;
		arr = new float[size];
		for (int i = 0; i < size; ++i) {

			arr[i] = val;
		}

	}
	darray(int size, float value ) {
		this->size = size;
		arr = new float[size];
		for (int i = 0; i < size; ++i) {
			arr[i] = value;
		}

	}

	void printArr() {
		for (int i = 0; i < size; ++i) {
			if (arr[i] == 0.0f) {
				std::cout << "[" << "0.0" << "]" << " ";
			}
			else {
				std::cout << "[" << arr[i] << "]" << " ";
			}
			
			
		}
		std::cout << "\n";
	}

	int countElements() {
		return size;
	}
	int countSize() {
		std::cout << typeid(*arr).name() << "\n";
		return countElements() * sizeof(*arr);

	}

	bool pushback(float f) {


		for (int i = 0; i < size; ++i) {
			if (arr[i] == 0.0f) {
				arr[i] = f;

				return false;
			}
		}
		float * arr2 = new float[size * 2];

		for (int i = 0; i < size; ++i) {

			arr2[i] = arr[i];
		}

		arr2[size] = f;

		for (int i = size + 1; i < size * 2; ++i) {

			arr2[i] = 0.0f;
		}
		delete[] arr;

		arr = arr2;

		size = size * 2;
		return true;

	}
	float&  operator[] (int index) {
		if (index > size) {
			std::cout << "Przekroczono zakrest tablicy";
			exit(0);
		}

		return arr[index];
	}
	
	~darray() {
		delete[] arr;
		std::cout << "deleting array \n";
	}



private:
	float * arr;
	int size;


};

class darray2 {

public:

	darray2() {}

	darray2(int size) {
		this->size = size;
		float val = 0.0f;
		arr = (float*) malloc(size * sizeof(float));
		for (int i = 0; i < size; ++i) {

			arr[i] = val;
		}

	}
	darray2(int size, float value) {
		this->size = size;
		arr = (float*)malloc(size * sizeof(float));
		for (int i = 0; i < size; ++i) {
			arr[i] = value;
		}

	}

	void printArr() {
		for (int i = 0; i < size; ++i) {
			if (arr[i] == 0.0f) {
				std::cout << "[" << "0.0" << "]" << " ";
			}
			else {
				std::cout << "[" << arr[i] << "]" << " ";
			}


		}
		std::cout << "\n";
	}

	int countElements() {
		return size;
	}
	int countSize() {
		std::cout << typeid(*arr).name() << "\n";
		return countElements() * sizeof(*arr);

	}

	//friend class ostream;

	friend std::ostream& operator<< (std::ostream& os, darray2& a) {
		
		a.printArr();
		return os;
	}

	float&  operator[] (int index) {
		if (index > size) {
			std::cout << "Przekroczono zakrest tablicy";
			exit(0);
		}

		return arr[index];
	}


	bool pushback(float f) {

	
		for (int i = 0; i < size; ++i) {
			if (arr[i] == 0.0f ) {
				arr[i] = f;
				
				return false;
			}
		}

		arr = (float * )realloc(arr,2 * size * sizeof(float));

		arr[size] = f;

		for (int i = size + 1; i < size * 2; ++i) {

			arr[i] = 0.0f;
		}

		size = size * 2;
		
		return true;

	}

	~darray2() {
	
		
		free(arr);
		std::cout << "deleting array \n";
	}



private:
	float * arr;
	int size;


};


int main()
{
	/*
	darray a(10, 0.1f);
	//a.printArr();

	//darray b(5);
	//b.printArr();

	darray * c, * d;
	c = new darray(2);
	d = new darray(3, 21);

	c->printArr();
	d->printArr();

	delete c;
	delete d;
	*/

	
	/*
	long a = 0;
	while (true) {


		a++;
		std::cout << a << "\n";
		//darray2 a(100, 0.1f);
		
	}

	return 0 ;
	
	*/
	/*
	darray e(5, 0.5f);
	
	e.printArr();
	std::cout << e.countElements() << "\n";
	std::cout << e.countSize() << "\n";

	std::cout << e.pushback(2.1f) << "\n";

	e.printArr();
	std::cout << e.countElements() << "\n";
	std::cout << e.countSize() << "\n";
	*/

	darray2 e(5, 0.5f);



	std::cout << e[6] << "\n";
	
};
