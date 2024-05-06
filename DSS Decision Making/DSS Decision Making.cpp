#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int EMVvalue;
int arr_subtract[3][3];
auto Table() {
	cout << "Enter The Tabel 3x3  : \n";

	int arr[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			cin >> arr[i][x];
		}

	}
	return arr;
}
auto Probability() {

	cout << "Enter the Probability of outcome 1x3: \n";


	double arrPro[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> arrPro[i];
	}
	return arrPro;
}

// Way
void Maximax(int arr[3][3]) {
	int maximax = 0;
	int NumProjectMaximax = 0;

	for (int a = 0; a < 3; a++)                                     
	{
		int maxvalueMaximax = arr[a][0];

		for (int s = 0; s < 3; s++)
		{
			if (maxvalueMaximax < arr[a][s])
				maxvalueMaximax = arr[a][s];

		}
		if (maximax < maxvalueMaximax)
		{
			maximax = maxvalueMaximax;
			NumProjectMaximax = a;
		}
	}
	cout << ">>>>>> Maximax <<<<<<<" << "\n";
	cout << "Max payoff : " << maximax << "\nFor the project : " << NumProjectMaximax + 1 << "\n";
}
//way
void Maximin(int arr[3][3]) {

	int maximin = 0;
	int NumProjectMaximin = 0;

	for (int a = 0; a < 3; a++)
	{
		int minvalueMaximin = arr[a][0];

		for (int s = 0; s < 3; s++)
		{
			if (minvalueMaximin > arr[a][s])
				minvalueMaximin = arr[a][s];

		}
		if (maximin < minvalueMaximin)
		{
			maximin = minvalueMaximin;
			NumProjectMaximin = a;
		}
	}
	cout << ">>>>>>>> Maximin <<<<<<<" << "\n";
	cout << "Max payoff : " << maximin << "\nFor the project : " << NumProjectMaximin + 1 << "\n";
}
// For Minimax Regret
void Minimax(int arr[3][3]) {

	int minimax = 0;
	int NumProjectMinimax = 0;
	int maxarr[3];

	for (int a = 0; a < 3; a++)
	{
		int maxvalueMinimax = arr[a][0];

		for (int s = 0; s < 3; s++)
		{
			if (maxvalueMinimax < arr[a][s])
				maxvalueMinimax = arr[a][s];

		}
		maxarr[a] = maxvalueMinimax;



	}
	for (int i = 0; i < 3; i++)
	{
		minimax = maxarr[0];
		if (minimax > maxarr[i])
		{
			minimax = maxarr[i];
			NumProjectMinimax = i;
		}
	}
	cout << ">>>>>>>> Minimax Regret <<<<<<<" << "\n";
	cout << "Max payoff : " << minimax << "\nFor the project : " << NumProjectMinimax + 1 << "\n";
}
//Way
void Minimax_Regret(int arr[3][3]) {

	int RNB[3];


	for (int i = 0; i < 3; i++)// for column 
	{

		int maxvalueMaximin = arr[0][i];

		for (int x = 0; x < 3; x++) // row
		{

			for (int z = i; z < i + 1; z++) // column
			{
				if (maxvalueMaximin < arr[x][z])
					maxvalueMaximin = arr[x][z];
			}
			RNB[i] = maxvalueMaximin;
		}

	}
	for (int i = 0; i < 3; i++)// for column 
	{
		for (int x = 0; x < 3; x++) // row
		{
			for (int z = i; z < i + 1; z++) // column
			{
				arr_subtract[x][z] = RNB[i] - arr[x][z];
			}

		}

	}


	Minimax(arr_subtract);


}
//Way
void EMV(int arr[3][3], double arrPro[3]) {

	double arrvalue[] = { 0,0,0 };


	for (int i = 0; i < 3; i++)
	{

		for (int x = 0; x < 3; x++)
		{
			arrvalue[i] += (arrPro[x] * arr[i][x]);
		}
	}



	double maxValue = *max_element(begin(arrvalue), end(arrvalue));
	EMVvalue = maxValue;
	cout << ">>>>>>>> EMV <<<<<<<" << "\n";
	cout << "Expected Monetary Value : " << maxValue << "\n";
	int NumberProject;
	for (int i = 0; i < 3; i++)
	{
		if (maxValue == arrvalue[i])
		{
			NumberProject = i;
			break;
		}
	}
	cout << "Number Project : " << NumberProject + 1 << "\n";
}
//way
void EOL(int arr[3][3], double arrPro[3]) {
	double arrvalue[] = { 0,0,0 };


	for (int i = 0; i < 3; i++)
	{

		for (int x = 0; x < 3; x++)
		{
			arrvalue[i] += (arrPro[x] * arr_subtract[i][x]);
		}
	}


	double maxValue = *min_element(begin(arrvalue), end(arrvalue));
	cout << ">>>>>>>> EOL <<<<<<<" << "\n";
	cout << "Expected Monetary Value : " << maxValue << "\n";
	int NumberProject;
	for (int i = 0; i < 3; i++)
	{
		if (maxValue == arrvalue[i])
		{
			NumberProject = i;
			break;
		}
	}
	cout << "Number Project : " << NumberProject + 1 << "\n";
}
//Way
void EVPI(int arr[3][3],double arrPro[3]) {
	int RNB[3];


	for (int i = 0; i < 3; i++)// for column 
	{

		int maxvalueMaximin = arr[0][i];

		for (int x = 0; x < 3; x++) // row
		{

			for (int z = i; z < i + 1; z++) // column
			{
				if (maxvalueMaximin < arr[x][z])
					maxvalueMaximin = arr[x][z];
			}
			RNB[i] = maxvalueMaximin;
		}

	}

	int EvpiValue=0;

	for (int i = 0; i < 3; i++)
	{
		EvpiValue += (RNB[i] * arrPro[i]);
	}

	
	cout << ">>>>>>>> EVPI <<<<<<<" << "\n";
	cout << "Expected Monetary Value : " << EvpiValue-EMVvalue << "\n";

}

int main()
{

	cout << "Enter The Tabel 3x3  : \n";
	int arr[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 3; x++)
		{
			cin >> arr[i][x];
		}

	}

	cout << "_____________________________________________________\n";
	Maximax(arr);
	cout << "_____________________________________________________\n";
	Maximin(arr);
	cout << "_____________________________________________________\n";
	Minimax_Regret(arr);

	cout << "_____________________________________________________\n";
	cout << "_____________________________________________________\n";
	cout << "_____________________________________________________\n";
	cout << "_____________________________________________________\n";
	cout << "_____________________________________________________\n";
	

	cout << "Enter the Probability of outcome 1x3: \n";
	double arrPro[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> arrPro[i];
	}

	cout << "_____________________________________________________\n";
	EMV(arr, arrPro);
	cout << "_____________________________________________________\n";
	EOL(arr, arrPro);
	cout << "_____________________________________________________\n";
	EVPI(arr, arrPro);
	

}
