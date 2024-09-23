#include"LexPermutations.h"
#include<iostream>
#include<vector>
#include<algorithm>

unsigned long long LexPermutations::getFactorial(unsigned int N) {
	if (N == 0) return 1;
	return N * getFactorial(N - 1);
}

void LexPermutations::Input() {
	string N;
	do {
		try {
			cout << "Введіть кількість елементів множини як натуральне число: ";
			getline(cin, N);
			if (stol(N) <= 0) {
				cout << "Кількість елементів некоректно введено" << endl;
				continue;
			}
			this->N = stoul(N);
			cout << "Множина задана успішно." << endl;
		}
		catch (const std::invalid_argument&) {
			cerr << "Неправильно введені числове значення, спробуйте ще раз" << endl;
			continue;
		}
		break;
	} while (true);
}

void LexPermutations::printLowestPerm() {
	cout << "Найменша перестановка елементів множини: {";	
	for (size_t i = 1; i < this->N; i++)
		cout << i << ", ";
	cout << this->N << "}." << endl;
}

vector<vector<int>> LexPermutations::find() {
	vector<vector<int>> permutations;
	vector<int>permutation = vector<int>(this->N);

	for (int i = 0; i < this->N ; i++) 
		permutation[i] = i + 1;

	cout << "i = " << 1 << "\t{";

	for (int i = 0; i < this->N - 1; i++) 		
		cout << permutation[i] << ", ";	
	cout << permutation[this->N - 1] << "}." << endl;

	permutations.push_back(permutation);

	for (size_t i = 1; i < getFactorial(this->N); i++) {
		int j = this->N - 2;

		// Search of j when left side woul'd be lower then right;
		while (j >= 0 && permutation[j] >= permutation[j + 1]) {
			j--;
		}
		if (j < 0) {
			break;
		}

		int k = this->N - 1;
		// Search of element with index k, which woul'd be greater then j
		while (permutation[k] <= permutation[j]) {
			k--;
		}

		//Swapping element j with next minimum after j element
		swap(permutation[j], permutation[k]);

		//Sorting tail for generated permutation
		reverse(permutation.begin() + j + 1, permutation.end());
		
		cout << "i = " << i + 1 << "\t{";
		for (int l = 0; l < this->N - 1; l++) {
			cout << permutation[l] << ", ";
		}
		cout << permutation[this->N - 1] << "}." << endl;
		permutations.push_back(permutation);
	}	
	return permutations;
};

LexPermutations::LexPermutations(string N) {
	if (stol(N) <= 0) {
		this->Input();
	} else
		this->N = stoul(N);
};