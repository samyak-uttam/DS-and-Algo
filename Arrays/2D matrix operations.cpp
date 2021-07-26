#include<bits/stdc++.h>
using namespace std;

// transpose of a 2D matrix
vector<vector<int>> transpose(vector<vector<int>>& mat) {
	int m = mat.size(), n = mat[0].size();
	vector<vector<int>> res(n, vector<int>(m));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			res[j][i] = mat[i][j];
	return res;
}


// rotate a n * n 2D matrix in clockwise direction
void rotateClk(vector<vector<int>>& mat) {
	int n = mat.size();
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			swap(mat[i][j], mat[j][i]);

	for (int i = 0, j = n - 1; i < j; i++, j--)
		for (int k = 0; k < n; k++)
			swap(mat[k][i], mat[k][j]);
}

// rotate a n * n 2D matrix in anti-clockwise direction
void rotateAntiClk(vector<vector<int>>& mat) {
	int n = mat.size();
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			swap(mat[i][j], mat[j][i]);

	for (int i = 0, j = n - 1; i < j; i++, j--)
		for (int k = 0; k < n; k++)
			swap(mat[i][k], mat[j][k]);
}

void printMat(vector<vector<int>>& mat) {
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[0].size(); j++)
			cout << mat[i][j] << " ";
		cout << "\n";
	}
}

int main() {
	vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	cout << "Original matrix:\n";
	printMat(mat);

	vector<vector<int>> tr = transpose(mat);
	cout << "\nTransposed matrix:\n";
	printMat(tr);

	rotateClk(mat);
	cout << "\nClockwise roation:\n";
	printMat(mat);

	rotateAntiClk(mat);
	cout << "\nAnti-Clockwise roation:\n";
	printMat(mat);
	return 0;
}