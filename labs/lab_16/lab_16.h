#include "../../libs/data_structures/matrix/matrix.h"
#include "../../libs/algorithms/array/array.h"


//Дана квадратная матрица, все элементы которой различны. Поменять местами
// строки, в которых находятся максимальный и минимальный элементы.
void exercise_1(matrix m);

//Упорядочить строки матрицы по неубыванию наибольших элементов строк:
void exercise_2(matrix m);

//Дана прямоугольная матрица. Упорядочить столбцы матрицы по неубыванию минимальных элементов столбцов.
void exercise_3(matrix m);

//Если данная квадратная матрица 𝐴 симметрична, то заменить 𝐴 ее квадратом (𝐴^2).
void exercise_4(matrix m);

//Дана квадратная матрица. Если среди сумм элементов строк матрицы нет равных, то транспонировать матрицу.
void exercise_5(matrix m);

//Даны две квадратные матрицы 𝐴 и 𝐵. Определить, являются ли они взаимно обратными (𝐴 = 𝐵^(−1)).
bool exercise_6(matrix m1, matrix m2);

//Дана прямоугольная матрица. Назовем псевдодиагональю множество элементов этой матрицы, лежащих на прямой,
// параллельной прямой, содержащей элементы 𝑎𝑖,𝑖. Найти сумму максимальных элементов всех псевдодиагоналей
// данной матрицы.
long long exercise_7(matrix m);

//Дана прямоугольная матрица, все элементы которой различны. Найти минимальный элемент матрицы в выделенной области
int exercise_8(matrix m);