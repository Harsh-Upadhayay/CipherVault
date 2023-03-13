#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

vector<vector<long long int>> GenerateKey(long long int Key_Size)
{
    vector<vector<long long int>> keyMatrix(Key_Size, vector<long long int>(Key_Size, 0));
    for (long long int i = 0; i < Key_Size; i++)
    {
        for (long long int j = 0; j < Key_Size; j++)
        {
            keyMatrix[i][j] = 1 + rand() % 128;
        }
    }
    return keyMatrix;
}
long long int determinantOfMatrix(vector<vector<long long int>> matrix) {
    long long int n = matrix.size();
    double det = 0.0;

    if (n == 1) {
        return matrix[0][0];
    }
    else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else {
        for (long long int j = 0; j < n; j++) {
            vector<vector<long long int>> submatrix(n-1, vector<long long int>(n-1));

            for (long long int i = 1; i < n; i++) {
                long long int k = 0;
                for (long long int l = 0; l < n; l++) {
                    if (l != j) {
                        submatrix[i-1][k] = matrix[i][l];
                        k++;
                    }
                }
            }

            double sign = (j % 2 == 0) ? 1.0 : -1.0;
            det += sign * matrix[0][j] * determinantOfMatrix(submatrix);
        }
    }

    return det;
}
vector<vector<long long int>> multiplyMatrices(vector<vector<long long int>> matrix1, vector<vector<long long int>> matrix2, long long int n, long long int m)
{
    vector<vector<long long int>> result(n, vector<long long int>(m, 0));
    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < m; j++)
        {
            for (long long int k = 0; k < n; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = result[i][j] % 128;
        }
    }
    return result;
}

vector<vector<long long int>> stringToMatrix(string input, long long int n, long long int m)
{
    vector<vector<long long int>> matrix(n, vector<long long int>(m, 0));
    long long int pos = 0;
    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < m; j++)
        {
            matrix[i][j] = (long long int)input[pos];
            pos++;
        }
    }
    return matrix;
}

string Encryption(string msg, long long int Key_Size)
{

    vector<vector<long long int>> Key = GenerateKey(Key_Size);



    if (determinantOfMatrix(Key) == 0 || gcd(determinantOfMatrix(Key), 128) != 1)
    {
    
        while (determinantOfMatrix(Key) == 0 || gcd(determinantOfMatrix(Key), 128) != 1)
        {
            // cout << determinantOfMatrix(Key) << "\n";
            Key = GenerateKey(Key_Size);
        }
    }

    for (auto it : Key)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }

    cout << determinantOfMatrix(Key) << endl;

    while (msg.size() % Key_Size != 0)
    {
        msg.push_back('x');
    }

    cout << msg << endl;

    vector<vector<long long int>> MsgMatrix = stringToMatrix(msg, Key_Size, msg.size() / Key_Size);

    for (auto it : MsgMatrix)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }

    cout << endl;

    string CipherText = "";
    vector<vector<long long int>> Cipher = multiplyMatrices(Key, MsgMatrix, Key_Size, msg.size() / Key_Size);

    for (auto it : Cipher)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
    //  cout << "1debug" << endl;
    

   

    for (long long int i = 0; i < Cipher.size(); ++i)
    {
        for (long long int j = 0; j < Cipher[0].size(); ++j)
        {
            char x = Cipher[i][j];
            CipherText.push_back(x);
        }
    }

    cout << CipherText << endl;
    return CipherText;
}
int main()
{
    srand(time(0));
    string msg = "Hel";
    long long int Key_Size = 2;
    string CipherText = Encryption(msg, Key_Size);
}