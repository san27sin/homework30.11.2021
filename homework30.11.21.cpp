/*
Homework 30.11.2021
created by Sinitsyn Alexander
*/

#include<iostream>
#include<cmath>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;

bool initializationArr_1(int* arr, int size)
{
	if (size > 0)
	{
		arr = new (std::nothrow) int[size];
		if (arr != nullptr)
		{
			for (int i = 0; i < size; ++i)
			{
				i == 0 ? (arr[i] = 1) : (arr[i] = pow(2, i));
				cout << arr[i] << "\t";
			}
			delete[] arr;
			arr = nullptr;
		}
	}
	else
	{
		cout << "Количество элементов в массиве введено 0!" << endl;
	}
	return true;
}




void combineTwoTxtFiles(string file_1, string file_2)
{
	
	ifstream file1(file_1);
	ifstream file2(file_2);


	
	string content;
	content += string(istreambuf_iterator<char>(file1),
		istreambuf_iterator<char>());
	content += string(istreambuf_iterator<char>(file2),
		istreambuf_iterator<char>());


	
	string nameOfCommonFile, commonfile;
	cout << "Введите название общего файла: " << endl;
	cin >> nameOfCommonFile;
	commonfile = nameOfCommonFile + ".txt";
	ofstream output_file(commonfile);
	output_file << content;
}


void main()
{
	setlocale(LC_ALL, "rus");
	srand(static_cast<unsigned int>(time(0)));
	/*
	==================================================================
	1. Выделить в памяти динамический одномерный массив типа int.
	Размер массива запросить у пользователя. Инициализировать его числами
	степенями двойки:1,2,4,8,16,32,64,128...Вывести массив на экран. Не 
	забыть освободить память. Разбить программу на функции.
	==================================================================
	*/
	cout << "Задача №1" << endl;

	int Arr_1[1];
	int theNumberOfelementsInArr;
	cout << "Введите количество элементов в массиве." << endl;
	cin >> theNumberOfelementsInArr;
	cout << "Элементов в массиве: "<< theNumberOfelementsInArr << endl;
	initializationArr_1(Arr_1, theNumberOfelementsInArr);
	
	/*
	==================================================================
	2.Динамически выделить матрицу 4х4 типа int. Инициализировать ее 
	псевдослучайными числами через функцию rand. вывести на экран. 
	Разбейте вашу программу на функции которые вызываются из main.
	==================================================================
	*/
	cout << "\n\nЗадача №2" << endl;
	int** ptrArr;
	const size_t m = 4;
	const size_t n = 4;

	ptrArr = new int* [m];
	for (size_t i = 0; i < m; i++)
	{
		ptrArr[i] = new int[n];
	}
	
	ptrArr[0][0] = 1;
	ptrArr[m - 1][n - 1] = 1;

	
	
	for (int i = 0; i < m; ++i)
	{
		for (int g = 0; g < n; ++g)
		{
			ptrArr[i][g] = rand()% 100;
			cout << ptrArr[i][g] << "\t";
			if (g == 3)
			{
				cout << endl;
			}
		}
	}

	for (size_t i = 0; i < m; ++i)
	{
		delete[]ptrArr[i];
	}

	delete[]ptrArr;
	ptrArr = nullptr;

	/*
	==================================================================
	3. Написать программу, которая создаст два текстовых файла(*.txt),
	примерно по 50-100 символов в каждом (особого значения не имеет с 
	каким именно содержимым). Имена файлов запросить у пользователя.
	==================================================================
	*/
	cout << "\n\nЗадача №3" << endl;

	string nameOfFirstFile, file_1;
	string nameOfSecondFile, file_2;
	cout << "Введите название первого файла." << endl;
	cin >> nameOfFirstFile;
	file_1 = nameOfFirstFile + ".txt";


	cout << "Введите название второго файла." << endl;
	cin >> nameOfSecondFile;
	file_2 = nameOfSecondFile + ".txt";

	ofstream fout1(file_1);
	fout1 << "I have a dream that my four little children will\none day live in a nation where they will not be\njudged by the color of their skin but by the\ncontent of their character.\n";
	fout1.close();

	ofstream fout2(file_2);
	fout2 << "Two roads diverged in a wood, and I, I took the\none less travelled by, and that has made all the\ndifference.\n";
	fout2.close();

	/*
	==================================================================
	4.Написать функцию, "склеивающую" эти файлы в третий текстовый файл
	(имя файлов спросить у пользователя).
	==================================================================
	*/
	combineTwoTxtFiles(file_1, file_2);

}
