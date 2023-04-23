#include <iostream>;
#include <clocale>;

using namespace std;

class TwoDimensionalArray {
private:
	int elementsCount;
public:
	double** doubleArray;

	int rows;
	int columns;

	TwoDimensionalArray(double** doubleArray, int rows, int columns) {
		this->doubleArray = doubleArray;

		this->rows = rows;
		this->columns = columns;

		for (int i = 0; i < rows; i++) {
			this->doubleArray[i] = new double[columns];
		}

		this->elementsCount = rows * columns;
	}

	TwoDimensionalArray& operator++ () {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				this->doubleArray[i][j] += 1;
			}
		}
		return *this;
	}

	TwoDimensionalArray& operator-- () {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				this->doubleArray[i][j] -= 1;
			}
		}
		return *this;
	}

	TwoDimensionalArray operator ++ (int) {
		TwoDimensionalArray copy(*this);
		++(*this);
		return copy;
	}

	TwoDimensionalArray operator -- (int) {
		TwoDimensionalArray copy(*this);
		--(*this);
		return copy;
	}

	operator bool() const {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns - 1; j++) {
				if (this->doubleArray[i][j] < this->doubleArray[i][j + 1]) {
					continue;
				}
				else {
					return false;
				}
			}
		}
		return true;
	}

	void fillArray() {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				cout << "Введите значение [" << i << "][" << j << "] элемента: ";
				cin >> this->doubleArray[i][j];
			}
		}
	}

	void showArray() {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				cout << this->doubleArray[i][j] << " ";
			}
			cout << endl;
		}
	}

	void sortArray() {
		double temp;
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns - 1; j++) {
				if (this->doubleArray[i][j] < this->doubleArray[i][j + 1]) {
					temp = this->doubleArray[i][j];
					this->doubleArray[i][j] = this->doubleArray[i][j + 1];
					this->doubleArray[i][j + 1] = temp;
				}
			}
		}
		cout << "Отсортированный массив: " << endl;
		this->showArray();
	}

	int getElementsCount() {
		return this->elementsCount;
	}

	void increaseElements(double value) {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				this->doubleArray[i][j] += value;
			}
		}
	}

	double getElement(int row, int column) {
		return this->doubleArray[row][column];
	}
};

int main() {
	setlocale(LC_CTYPE, "rus");

	int rows = 2;
	int columns = 2;

	double** doubleArray = new double* [rows];
	TwoDimensionalArray twoDimensionalArray(doubleArray, rows, columns);

	twoDimensionalArray.fillArray(); // вводим значения с клавиатуры
	twoDimensionalArray.showArray(); // выводим массив
	twoDimensionalArray.sortArray(); // сортируем массив в порядке убывания

	cout << "------------------------------------------------------------------------" << endl;

	double valueForIncrease = 1.5;

	int elementsCount = twoDimensionalArray.getElementsCount(); // получаем общее количество элементов массива
	cout << "Количество элементов - " << elementsCount << endl;

	cout << "Увеличиваем элементы на скаляр - " << valueForIncrease << endl;
	twoDimensionalArray.increaseElements(valueForIncrease);
	twoDimensionalArray.showArray();

	cout << "------------------------------------------------------------------------" << endl;

	double element = twoDimensionalArray.getElement(0, 1); // обращаемся к элементу по индексу
	cout << element << endl; 

	cout << "------------------------------------------------------------------------" << endl;

	cout << "Операция ++: " << endl;
	twoDimensionalArray++;
	twoDimensionalArray.showArray();

	cout << "Операция --: " << endl;
	twoDimensionalArray--;
	twoDimensionalArray.showArray();

	cout << endl;
	if (twoDimensionalArray) {
		cout << "Массив отсортирован по возрастанию" << endl;
	}
	else {
		cout << "Массив не отсортирован по возрастанию" << endl;
	}
}
