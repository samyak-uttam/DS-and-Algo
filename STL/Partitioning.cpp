#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> vec, int n)
{
	for (int i = 0; i < n; i++)
		cout << vec[i] << " ";
	cout << "\n";
}

int main()
{
	vector<int> vec = {2, 1, 5, 6, 8, 7};
	int n = vec.size();

	// is_partitioned, check whether the container is partitioned
	is_partitioned(begin(vec), end(vec), [](int x)
	{
		return x % 2 == 0;
	}) ? cout << "Vec is partitioned." : cout << "Vec is unpartitioned.";
	cout << "\n";


	// partition according to the conditioned mentioned
	partition(begin(vec), end(vec), [](int x)
	{
		return x % 2 == 0;
	});
	cout << "Vector after partitioning is: ";
	printVec(vec, n);


	// partition_point, to get ending position of partition
	auto it = partition_point(begin(vec), end(vec), [](int x)
	{
		return x % 2 == 0;
	});
	cout << "Partition point is: " << it - begin(vec);

	return 0;
}