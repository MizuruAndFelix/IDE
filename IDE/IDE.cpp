#include <algorithm> 
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;

void print(int* arr, int size) //вывод в консоль для проверки, чтоб не заблудиться
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}



int* create_array(int size) // создать динамический массив
{
	return new int[size]();
}



int main()
{
	setlocale(0, "");
	SetConsoleCP(1251); //перевод на русский
	SetConsoleOutputCP(1251);

	cout << "RUN!\n";

	ifstream fileIn("in.txt");
	if (!fileIn.is_open())
	{
		cout << "Eror!\n";
		return 0;
	}
	else
	{
		cout << "file open!\n";
		int dist = 1;
		int  size;
		int i;
		int Msize;
		int Nsize;
		fileIn >> size;
		Msize = size;

		int* arrM = create_array(size);

		for (i = 0; i < size && fileIn; ++i)
		{
			fileIn >> arrM[i];
		}

		for (int i = 0; i < Msize - 1; i++) //перемещение вправо
		{
			swap(arrM[i + 1], arrM[i]); //я протупил и поменяв местами все заработало
		}
		print(arrM, size); // контролирую чо получилось || все работает

		fileIn >> size;
		Nsize = size;
		dist = -1;
		int* arrN = create_array(size);

		for (i = 0; i < size && fileIn; ++i)
		{
			fileIn >> arrN[i];
		}

		for (int i = 1; i < Nsize; i++) // перемещение влево
		{
			swap(arrN[Nsize - i], arrN[Nsize - i - 1]); // перемещение цифр массива 10 20 30 40 50 60
		}

		print(arrN, size); // контролирую чо получилось || работает
		fileIn.close();

		ofstream fileOut("out.txt");
		if (!fileOut.is_open())
		{
			cout << "Eror!\n";
			return 0;
		}
		else
		{
			cout << "File open!\n";
			fileOut << Nsize << endl;
			for (int i = 0; i < Nsize; i++)
			{
				fileOut << arrN[i] << " ";
			}

			fileOut << endl << Msize << endl;
			for (int i = 0; i < Msize; i++)
			{
				fileOut << arrM[i] << " ";
			}
		}
		delete[] arrN;
		delete[] arrM;
		fileOut.close();
	}

	return 0;
}