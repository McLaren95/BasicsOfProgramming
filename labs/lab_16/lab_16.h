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

//Дано 𝑛 точек в 𝑚-мерном пространстве. Упорядочить точки по неубыванию их расстояний до начала координат.
void exercise_9(matrix m);

//Определить количество классов эквивалентных строк данной прямоугольной матрицы.
// Строки считать эквивалентными, если равны суммы их элементов.
int exercise_10(matrix m);

//Дана матрица. Определить 𝑘 – количество "особых" элементов матрицы, считая
//элемент "особым" , если он больше суммы остальных элементов своего столбца.
int exercise_11(matrix m);

//Дана квадратная матрица. Заменить предпоследнюю строку матрицы первым
//из столбцов, в котором находится минимальный элемент матрицы.
void exercise_12(matrix m);

//Дан массив матриц одного размера. Определить число матриц, строки которых упорядочены по неубыванию элементов
int exercise_13(matrix *ms, int n);

//Дан массив целочисленных матриц. Вывести матрицы, имеющие наибольшее
//число нулевых строк
void exercise_14(matrix *ms, int n);

//. Дан массив целочисленных квадратных матриц. Вывести матрицы с наименьшей нормой.
// В качестве нормы матрицы взять максимум абсолютных величин ее элементов.
void exercise_15(matrix *ms, int n);
