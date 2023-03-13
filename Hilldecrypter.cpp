#include <iostream> 
#include <vector> 
const int MOD = 128; 
using namespace std; 


 
// returns the modular inverse of x in mod p 
int modInverse(int x, int p) { 
    int y = 0, z = 1; 
    while (x > 1) { 
        int q = x / p; 
        int t = p; 
        p = x % p, x = t; 
        t = y; 
        y = z - q * y; 
        z = t; 
    } 
    return (z + MOD) % MOD; 
} 
 
// prints the matrix 
void printMatrix(vector<vector<int>> &a) { 
    int n = a.size(), m = a[0].size(); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            cout << a[i][j] << " "; 
        } 
        cout << endl; 
    } 
} 
// Function to get the cofactor of a matrix element
void getCofactor(vector<vector<int>> A, vector<vector<int>>& temp, int p, int q, int N)
{
    int i = 0, j = 0;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
                if (j == N - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
// Function to calculate the determinant of a matrix
int determinant(vector<vector<int>> A, int N)
{
    int det = 0;
    if (N == 1)
    {
        return A[0][0];
    }
    else if (N == 2)
    {
        return ((A[0][0] * A[1][1]) - (A[1][0] * A[0][1]));
    }
    else
    {
        vector<vector<int>> temp(N-1, vector<int>(N-1));
        int sign = 1;
        for (int i = 0; i < N; i++)
        {
            getCofactor(A, temp, 0, i, N);
            det += sign * A[0][i] * determinant(temp, N - 1);
            sign = -sign;
        }
    }
    return det;
}
// Function to find the adjoint of a matrix
void adjoint(vector<vector<int>> A, vector<vector<int>>& adj, int N)
{
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }

    int sign = 1;
    vector<vector<int>> temp(N-1, vector<int>(N-1));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Get the cofactor of element A[i][j]
            getCofactor(A, temp, i, j, N);
            // Determine the sign of the adjoint element
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            // Assign the sign to the adjoint element
            adj[j][i] = sign * determinant(temp, N - 1);
        }
    }
}

vector<vector<int>> multiplyMatrices(vector<vector<int>> matrix1, vector<vector<int>> matrix2, int n, int m)
{
    vector<vector<int>> result(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = result[i][j] % 128;
        }
    }
    return result;
}
 
// calculates the inverse of a matrix in mod 128 
vector<vector<int>> inverse(vector<vector<int>> &a) { 
    // int n = a.size(), m = a[0].size(); 
    // vector<vector<int>> res(n, vector<int>(m * 2, 0)); 
    // for (int i = 0; i < n; i++) { 
    //     for (int j = 0; j < m; j++) { 
    //         res[i][j] = a[i][j]; 
    //     } 
    //     res[i][i + m] = 1; 
    // } 
    // for (int i = 0; i < n; i++) { 
    //     int j = i; 
    //     while (j < n && res[j][i] == 0) j++; 
    //     if (j == n) { 
    //         cout << "Matrix is not invertible" << endl; 
    //         exit(0); 
    //     } 
    //     swap(res[i], res[j]); 
    //     int inv = modInverse(res[i][i], MOD); 
    //     for (int k = i; k < m * 2; k++) { 
    //         res[i][k] = (res[i][k] * inv) % MOD; 
    //     } 
    //     for (int k = 0; k < n; k++) { 
    //         if (k != i) { 
    //             int c = res[k][i]; 
    //             for (int l = i; l < m * 2; l++) { 
    //                 res[k][l] = (res[k][l] - c * res[i][l] + MOD) % MOD; 
    //             } 
    //         } 
    //     } 

    // } 
    // vector<vector<int>> ans(n, vector<int>(m, 0)); 
    // for (int i = 0; i < n; i++) { 
    //     for (int j = 0; j < m; j++) { 
    //         ans[i][j] = res[i][j + m]; 
    //     } 
    // } 
    // cout<<ans.size()<<endl;
    // return ans; 


    
} 
 
int main() { 
    // int Key_Size;
    // cin>>Key_Size;
    // vector<vector<int>> Key ;
    // for(int i=0;i<Key_Size;++i){
    //     vector<int>temp;
    //     for(int j=0;j<Key_Size;++j){
    //         int a;cin>>a;
    //         temp.push_back(a);
    //     }
    //     Key.push_back(temp);
    // }
    // cout << "Matrix A:\n"; 
    // printMatrix(Key); 
    // vector<vector<int>> inv = inverse(Key); 
    // cout<<inv.size();
    
    // cout << "Inverse of A:\n"; 
    // printMatrix(inv); 
    // return 0; 
    int N = 4;
    vector<vector<int>> A = {{91, 33, 0,62},
                             {38, 123, 3,71},
                             {22, 69, 16,25},
                             {111,6,38,12}};
    vector<vector<int>> adj(N, vector<int>(N));
    adjoint(A, adj, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    int det = determinant(A,N);
    cout<<det<<"\n";
    det = abs(det);
    long long inv = modInverse(det,128);

    cout<<inv<<"\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            adj[i][j] *= inv;
        }
    }

    vector<vector<int>>cip= {{48},{32},{88},{120}};

    vector<vector<int>>ret = multiplyMatrices(adj,cip,N,1);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            ret[i][j]%=128;
            if(ret[i][j] < 0){
                ret[i][j] += 128;
            }
        }
        
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 1; ++j)
        {
            char x = ret[i][j];
            cout<<x<<" ";
        }
        cout<<"\n";
    }



    return 0;
}

