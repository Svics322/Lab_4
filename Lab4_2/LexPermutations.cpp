#include"LexPermutations.h"
#include<iostream>
#include<vector>
#include<algorithm>

unsigned long long LexPermutations::getFactorial(unsigned int N) {
	if (N == 0) return 1;
	return N * getFactorial(N - 1);
}

void LexPermutations::Input() {
	string N, R;
	do {
		try {
			cout << "Введіть кількість елементів множини як натуральне число: ";
			getline(cin, N);
			if (stol(N) <= 0) {
				cout << "Кількість елементів некоректно введено" << endl;
				continue;
			}
			cout << "Введіть невід'ємне ціле число: ";
			getline(cin, R);
			if (stol(R) <= 0 && stol(R) < stol(N)) {
				cout << "Кількість елементів некоректно введено" << endl;
				continue;
			}
			this->N = stoul(N);
			this->R = stoul(R);
			cout << "Множина успішно задана." << endl;
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
	for (size_t i = 1; i < this->R; i++)
		cout << i << ", ";
	cout << this->R << "}." << endl;
}

bool LexPermutations::nextCombination(vector<int>& permutations) {
	int i = this->R - 1;
	while (i >= 0 && permutations[i] == this->N - this->R + i + 1) {
		i--;
	}
	if (i < 0) {
		return false;
	}
	permutations[i]++;
	for (size_t j = i + 1; j < this->R; ++j) {
		permutations[j] = permutations[j - 1] + 1;
	}
	return true;
}

vector<vector<int>> LexPermutations::find() {
	vector<vector<int>> permutations;
	vector<int>permutation = vector<int>(this->R);

	for (int i = 0; i < this->R; i++)
		permutation[i] = i + 1;

	cout << "i = " << 1 << "\t{";

	for (int i = 0; i < this->R - 1; i++)
		cout << permutation[i] << ", ";
	cout << permutation[this->R - 1] << "}." << endl;

	permutations.push_back(permutation);

	int i = 1;
	while(nextCombination(permutation)){		
		permutations.push_back(permutation);

		cout << "i = " << i + 1 << "\t{";

		for (int l = 0; l < this->R - 1; l++) {
			cout << permutation[l] << ", ";
		}
		cout << permutation[this->R - 1] << "}." << endl;
		i++;
	}
	return permutations;
};

LexPermutations::LexPermutations(string N, string R) {
	if (stol(N) <= 0 && stol(R) < stol(N)) {
		this->Input();
	}
	else {
		this->N = stoul(N);
		this->R = stoul(R);
	}
};