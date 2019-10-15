#include<iostream>
using namespace std;
int n, m;
int A[100][100], rB[100], rR[100], B[100][100];

void rMove(){
	int i=0, sum_rB = 0, sum_rR = 0;
	int temp;
	int x_rB = 0, y_rB = 0;
	int x_rR = n-1, y_rR = n-1;
	int rotate_rB = 0; // 0: down
	int rotate_rR = 0; // 0: up      rotate left -> rotate++ / rotate right -> rotate--;
	
	while(i < m){
		if(rB[i] == 0){
			if(rotate_rB%4 == 0)
				x_rB++;
			else if(rotate_rB%4 == 1 || rotate_rB%4 == -3)
				y_rB++;
			else if(rotate_rB%4 == 3 || rotate_rB%4 == -1)
				y_rB--;
			else if(rotate_rB%4 == 2 || rotate_rB%4 == -2)
				x_rB--;			
			sum_rB += A[x_rB][y_rB];
			temp = A[x_rB][y_rB];
			A[x_rB][y_rB] = 0;
		}else{
			if(rB[i] == 1)
				rotate_rB++;
			else
				rotate_rB--;
		}
		
		if(rR[i] == 0){
			if(rotate_rR%4 == 0)
				x_rR--;
			else if(rotate_rR%4 == 1 || rotate_rR%4 == -3)
				y_rR--;
			else if(rotate_rR%4 == 3 || rotate_rR%4 == -1)
				y_rR++;
			else if(rotate_rB%4 == 2 || rotate_rB%4 == -2)
				x_rR++;
			sum_rR += B[x_rR][y_rR]; 
			B[x_rR][y_rR] = 0;
		}else{
			if(rR[i] == 1)
				rotate_rR++;
			else
				rotate_rR--;		
		}
		
		if(x_rB == x_rR)
			if(y_rB == y_rR){
				sum_rB -= temp;
				sum_rR -= temp;
				break;
			}
		i++;
	}
	cout << sum_rB << " " << sum_rR << endl;
}

int main(){
	int T;
	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> n >> m;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin >> A[i][j];	
		for(int i=0; i<m; i++)
			cin >> rB[i];
		for(int i=0; i<m; i++)
			cin >> rR[i];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				B[i][j] = A[i][j];
				
		rMove();
	}
	return 0;
}
