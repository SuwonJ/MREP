#include<iostream>
#include<chrono>

using namespace std;

bool firstMeasure = true;
chrono::high_resolution_clock::time_point startTime, endTime;
void measureTime(string msg)
{
	if (firstMeasure) 
	{
		startTime = chrono::high_resolution_clock::now();
		firstMeasure = false;		
	}
	else
	{
		endTime = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> time_span = endTime - startTime;
		cout << msg << " " << time_span.count() << " ms\n";
		startTime = endTime;
	}

	return;
}

int main() 
{
	measureTime("");
	
	int result = 1;
	for (int i = 1; i < 10000000; i++)
		result += i;

	measureTime("add");

	for (int i = 1; i < 10000000; i++)
		result *= i;

	measureTime("mult");

	for (int i = 1; i < 10000000; i++) 
		result /= i;

	measureTime("div");

	return 0;
}