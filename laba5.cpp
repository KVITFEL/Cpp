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

	TwoDimensionalArray(double** doubleArray, int columns) {
		this->doubleArray = doubleArray;

		this->rows = sizeof(this->doubleArray) / sizeof(this->doubleArray[0]);
		this->columns = columns;

		for (int i = 0; i < rows; i++) {
			this->doubleArray[i] = new double[this->columns];
		}

		elementsCount = this->rows * this->columns;
	}

	TwoDimensionalArray operator++ () {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				this->doubleArray[i][j] += 1;
			}
		}
	}

	TwoDimensionalArray operator-- () {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				this->doubleArray[i][j] += 1;
			}
		}
	}

	void fillArray(int row, int column, double value) {
		this->doubleArray[row][column] = value;
	}

	void showArray() {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				cout << this->doubleArray[i][j] << " ";
			}
			cout << endl;
		}
	}

	double** sortArray() {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				double temp = this->doubleArray[i][j];
				if (this->doubleArray[i][j] < this->doubleArray[i][j + 1]) {
					this->doubleArray[i][j] = this->doubleArray[i][j + 1];
					this->doubleArray[i][j + 1] = temp;
				}
			}
		}
		return this->doubleArray;
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
}
