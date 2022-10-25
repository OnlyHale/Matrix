/***************************************************************************************
*Project Name : Matrix                                                                 *
*File Name    : Matrix.cpp                                                             *
*Language     : CPP,MSVS ver 2015 and above                                            *
*Programmers  : Ратников Роман Олегович,Фицайло Александр Александрович,               *
*                               группа:М3О-110Б-20                                     *
*Modified By  :                                                                        *
*Created      : 02/04/2021                                                             *
*Last Revision: 21/04/2021                                                             *
*Comment      : Двумерные массивы                                                      *
***************************************************************************************/


#include <iostream>
#include <fstream>
using namespace std;
const int MaxN = 10;        //Максимальное количество строк и чисел в строке

//Функция записи и печати матрицы
int IntMatr(const char* fName,  //   Файл
	int Matr[][MaxN],           //   Матрица
	int& N,                     //   Число строк
	int& M)                     //   Число столбцов в матрице
{   //Изначально нет ошибок
	int Error = 0;
	fstream fin;
	fin.open(fName);
	//Проверка на существование файла
	if (!fin)
	{
		cout << " Файл "<<fName<<" не найден" << endl;			//Сообщение об ошибке
		fin.close();					            //Закрыть файл
		Error = 1;                               //Появилась ошибка
		return Error;					                //Выход по ошибке
	}
	//Проверка на пустоту файл
	if (fin.peek()== EOF)
	{
		cout << " Файл "<< fName<< " пуст" << endl;
		fin.close();
		Error = 2;                           
		return Error;
	}

	fin >> N >> M;
	//Проверка ввода на корректные данные
	if (fin.fail())
	{
		fin.close();
		cout << " Ошибка ввода . Некорректные данные."<<endl;
		Error = 3;
		return Error;
    }
	    //Технологическая печать 
       cout << " N = " << N << endl;
	   cout << " M = " << M << endl;
        //Проверка на натуральность N
	   if (N <= 0 )
	   {
		   fin.close();
		   cout << " Ошибка ввода .N не может быть меньше 1 " <<  endl;
		   Error = 4;
		   return Error;
	   }
	   //Проверка на натуральность M
	   if (M <= 0)
	   {
		   fin.close();
		   cout << " Ошибка ввода .M не может быть меньше 1 " << endl;
		   Error = 5;
		   return Error;
	   }
	// Проверка на превышение MaxN
	if (N > MaxN )
	{
		fin.close();
		cout << " Ошибка ввода .N не может быть больше " << MaxN<<endl;
		Error = 6;
		return Error;
	}
	// Проверка на превышение MaxN
	if (M > MaxN)
	{
		fin.close();
		cout << " Ошибка ввода . M не может быть больше " << MaxN << endl;
		Error = 7;
		return Error;
	}
	
	//Запись матрицы
	for (int i = 0;i < N;i++)
	{
		for (int j = 0; j < M;j++)
		{
			
			//Если недостаточно данных
			 if (fin.eof())
			 {
				fin.close();
				cout << " Ошибка ввода. Недостаточно данных." << endl;
				Error = 8;
				return Error;

			 }

            fin >> Matr[i][j];
			//Если встречены некорректные данные
			if (fin.fail())
			{
				fin.close();
				cout << " Ошибка ввода .Некорректные данные ." << endl;
				Error = 9;
				return Error;
			}
		}
	}   
	//Если превышено количество данных
	if (!fin.eof())
    {
		fin.close();
		cout << " Ошибка ввода . Превышено количество данных." << endl;
		Error = 10;
		return Error;


	}
	//Печать матрицы
	for (int i = 0;i < N;i++)
	{
		for (int j = 0; j < M;j++)
			cout<<' '<< Matr[i][j] << ' ';
		cout << endl;
	}
	return Error;
}


// Функция определения максимального числа,которое повторялось в матрице
void MAXP ( int Matr[][MaxN], int N, int M)
{   //Индексовые переменные
	int i;
	int j;
	//Переменная для сохранения значения
	int Bufer;
	
	int max;   // Максимальное значение , которое повторялось
	//Изначально нет повтора чисел в матрице
	bool Repeat = false;
	int arrMAXP[MaxN*MaxN]; // Вектор для сортировки
    //Запись матрицы в вектор
	for (i = 0;i < N;i++)
	{
		for (j = 0;j < M;j++)
		{
			arrMAXP[i * M + j] = Matr[i][j];
		}

	}
	
    //Сортировка чисел от большего значения к меньшему 
	for (i=0;i<N*M;i++)
	{
		for (j = N * M - 1; j > 0;j--)

		{
			if (arrMAXP[j] > arrMAXP[j - 1])

			{
				Bufer = arrMAXP[j - 1];
				arrMAXP[j - 1] = arrMAXP[j];
				arrMAXP[j] = Bufer;
			}
        }


	}


	/*  Проверка
	cout << '\n';
	for (i = 0;i < N * M;i++)
		cout << arrMAXP[i] << ' ';
	cout << '\n';
	*/
	
	
	//Поиск первого повторяющегося числа


	for (i = 0;i < N * M - 1;i++)
	{
		if (arrMAXP[i] == arrMAXP[i + 1])
		{
			Repeat = true;
			max = arrMAXP[i];
			break;
		}

		
	}
	//Если есть повтор
	if (Repeat)
	{
		cout << " Максимальное число , которое повторяется:  " << max<<endl;
	}
	else
	{
		cout << " В матрице нет повторяющихся чисел" << endl;
	}
	
}
//Подсчёт строк в матрице, в которых нет чётных чисел
void CHET( int Matr[][MaxN], int N, int M)

 {
	
	
		int Counter = N;      //Всего строк
		for (int i = 0;i < N; i++)
		{
			for (int j = 0;j < M;j++)
			{
				if (Matr[i][j] % 2 == 0)  //Если есть чётное число в строке
				{
					Counter--;
					break;
				}
			}
		}
		cout << " Количество строк  без  чётных чисел: " << Counter << endl;
	
 }

int main()
{
	setlocale(LC_ALL, "Rus");         //Русский язык в консоли
		system("color F0");           //Белая консоль,чёрные буквы
		//Двумерные массивы
		int A[MaxN][MaxN];            
		int B[MaxN][MaxN];
		
		int N;  //Кол-во строк
		int M;  //Кол-во чисел в строке(Столбцов)

		//const char* fName = "A.txt";         // Корректный тест
		const char* fName = "A0.txt";      // Корректный тест , нет повторяющихся чисел
		//const char* fName = "Aф.txt";      // Некорректный тест.Несуществующий файл
		//const char* fName = "A1.txt";      // Некорректный тест.Пуcтой файл
		//const char* fName = "A2.txt";      // Некорректный тест.Некорректные N и M
		//const char* fName = "A3.txt";      // Некорректный тест. N или M не целые
		//const char* fName = "A4.txt";      // Некорректный тест. N или M больше MaxN
		//const char* fName = "A5.txt";      // Некорректный тест. Числа в матрице некорректные
		//const char* fName = "A6.txt";      // Некорректный тест. Недостаточно данных
		//const char* fName = "A7.txt";      // Некорректный тест , N меньше 1
		//const char* fName = "A8.txt";      // Некорректный тест , M меньше 1
		//const char* fName = "A9.txt";      // Некорректный тест , Превышено количество данных




		//const char* fName2 = "B0.txt";      // Корректный тест , нет повторяющихся чисел
		const char* fName2 = "B.txt";       // Корректный тест
		//const char* fName2 = "Ba.txt";      // Некорректный тест.Несуществующий файл
		//const char* fName2 = "B1.txt";      // Некорректный тест .Пуcтой файл
		//const char* fName2 = "B2.txt";      // Некорректный тест.Некорректные N или M
		//const char* fName2 = "B3.txt";      // Некорректный тест. N или M не целые
		//const char* fName2 = "B4.txt";      // Некорректный тест. N или M больше MaxN
		//const char* fName2 = "B5.txt";      // Некорректный тест. Числа в матрице некорректные
		//const char* fName2 = "B6.txt";      // Некорректный тест. Недостаточно данных
		//const char* fName2 = "B7.txt";      // Некорректный тест , N меньше 1
		//const char* fName2 = "B8.txt";      // Некорректный тест , M меньше 1
		//const char* fName2 = "B9.txt";      // Некорректный тест , Превышено количество данных
		
	
		
		int Error  ;
		cout << "\t Матрица А" << endl;
		Error = IntMatr(fName, A, N, M);
		if (Error == 0)
		{
			CHET(A, N, M);
		    MAXP( A, N, M);

		}
		
		
		Error = 0;  //Изначально ошибок нет в следующей матрице перед проверкой
		
		cout << "\t Матрица B" << endl;
		Error = IntMatr(fName2,B , N, M);
		if (Error == 0)
		{
			CHET(B, N, M);
			MAXP( B, N, M);

		}
		
		

		return Error;
}
