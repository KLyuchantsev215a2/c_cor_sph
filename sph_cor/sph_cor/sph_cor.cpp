// sph_cor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
double* initialization_x(int N, int sqn, double l) {
	int i = 1;
	double* x ;

	for  yi = 1:sqn
		for  xi = 1 : sqn
			x(1, i) = xi / sqn * l;
	x(2, i) = yi / sqn * l;
	i = i + 1;
	end
		end

		init = x;
}
int main()
{
	double rho_0 = 1.2;
	double  v_0 = 0.1;
	double Time = 10;
	
	int sqn = 10;
	double l = 0.01;
	int N = sqn * sqn;
	double S = l * l;
	double m = rho_0 * S / double(N);
	
	double h = 0.8*sqrt((m / rho_0));
	double dt = 0.001;
	double dh = 0.00000001;
	
	double *V = new double(N);
	for(int i=0;i<N;i++)
		V[i]=m / rho_0; //m / rho_0;
	
	double *x = initialization_x(N, sqn, l);
	double *v = initialization_v(N, sqn, v_0, x);

	F = zeros(2, 2, N);

	for i = 1:N
		F(1:2, 1 : 2, i) = eye(2);
	end

		for n = 1:fix(Time / dt)
			W_cor = zeros(N, N);
	W_cor_1per = zeros(N, N);
	W_cor_2per = zeros(N, N);
	nabla_W_cor = zeros(2, N, N);
	W_cor = ComputeW_cor(N, x, x, V, h);
	x_per1 = x;
	x_per2 = x;

	x_per1(1, 1:N) = x_per1(1, 1:N) + dh;
	x_per2(2, 1:N) = x_per2(2, 1:N) + dh;

	W_cor_1per = ComputeW_cor(N, x, x_per1, V, h);
	W_cor_2per = ComputeW_cor(N, x, x_per2, V, h);

	nabla_W_cor(1, 1:N, 1 : N) = (W_cor_1per - W_cor) / dh;
	nabla_W_cor(2, 1:N, 1 : N) = (W_cor_2per - W_cor) / dh;



	L = ComputeL(v, V, nabla_W_cor, N);



	for i = 1:N
		v(2, i) = (x(2, i))*v_0;
	end

		for i = 1:N
			x(2, i) = x(2, i) + dt * v(2, i);
	end

		V = computeV(N, W_cor);

	for i = 1:N
		dtLL = dt * L(1:2, 1 : 2, i);
	F(1:2, 1 : 2, i) = expm(dtLL)*F(1:2, 1 : 2, i);
	end

		plotmy = myplot(x, V, F, N);

	end

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
