#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> GenerateKey(int Key_Size)
{
    srand(time(0));
    vector<vector<int>> keyMatrix(Key_Size, vector<int>(Key_Size, 0));
    for (int i = 0; i < Key_Size; i++)
    {
        for (int j = 0; j < Key_Size; j++)
        {
            keyMatrix[i][j] = rand() % 128;
        }
    }
    return keyMatrix;
}
int determinantOfMatrix(vector<vector<int>> Key)
{
    int n = Key.size();

    int num1, num2, det = 1, index,
                    total = 1; // Initialize result

    // temporary array for storing row
    int temp[n + 1];

    // loop for traversing the diagonal elements
    for (int i = 0; i < n; i++)
    {
        index = i; // initialize the index

        // finding the index which has non zero value
        while (index < n && Key[index][i] == 0)
        {
            index++;
        }
        if (index == n) // if there is non zero element
        {
            // the determinant of matrix as zero
            continue;
        }
        if (index != i)
        {
            // loop for swapping the diagonal element row and
            // index row
            for (int j = 0; j < n; j++)
            {
                swap(Key[index][j], Key[i][j]);
            }
            // determinant sign changes when we shift rows
            // go through determinant properties
            det = det * pow(-1, index - i);
        }

        // storing the values of diagonal row elements
        for (int j = 0; j < n; j++)
        {
            temp[j] = Key[i][j];
        }
        // traversing every row below the diagonal element
        for (int j = i + 1; j < n; j++)
        {
            num1 = temp[i];   // value of diagonal element
            num2 = Key[j][i]; // value of next row element

            // traversing every column of row
            // and multiplying to every row
            for (int k = 0; k < n; k++)
            {
                // multiplying to make the diagonal
                // element and next row element equal
                Key[j][k] = (num1 * Key[j][k]) - (num2 * temp[k]);
            }
            total = total * num1; // Det(kA)=kDet(A);
        }
    }

    // multiplying the diagonal elements to get determinant
    for (int i = 0; i < n; i++)
    {
        det = det * Key[i][i];
    }
    return (det / total); // Det(kA)/k=Det(A);
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

vector<vector<int>> stringToMatrix(string input, int n, int m)
{
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = (int)input[pos];
            pos++;
        }
    }
    return matrix;
}

string Encryption(string msg, int Key_Size)
{

    vector<vector<int>> Key = GenerateKey(Key_Size);

    if (determinantOfMatrix(Key) == 0)
    {

        while (determinantOfMatrix(Key) == 0)
        {
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

    vector<vector<int>> MsgMatrix = stringToMatrix(msg, Key_Size, msg.size() / Key_Size);

    for (auto it : MsgMatrix)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }

    cout << endl;

    string CipherText = "";
    vector<vector<int>> Cipher = multiplyMatrices(Key, MsgMatrix, Key_Size, msg.size() / Key_Size);

    for (auto it : Cipher)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
    //  cout << "1debug" << endl;
    

   

    for (int i = 0; i < Cipher.size(); ++i)
    {
        for (int j = 0; j < Cipher[0].size(); ++j)
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
    cout << "ENTER THE PLAIN TEXT" << endl;
    string msg;
    getline(cin, msg);
    int Key_Size;
    cout << "ENTER THE KEY SIZE ";
    cin >> Key_Size;
    string CipherText = Encryption(msg, Key_Size);
}