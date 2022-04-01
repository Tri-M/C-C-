

 #include <iostream>
    #include <cassert>

    int main()
    {
       int rowsA = 3;
       int colsA= 3;

       double** A;
       A = new double* [rowsA];
       A[0] = new double [rowsA*colsA];
       for (int i = 1; i < rowsA; i++)
       {
          A[i] = A[i-1] + colsA;
       }


       for(int i = 0; i < rowsA; ++i)

       {
          for(int j = 0; j < colsA; ++j)

          {

             std::cout << "Enter element A" << i + 1 << j + 1 << " : ";
             std::cin >> A[i][j];

          }
       }

       int rowsB = 3;
       int colsB = 3;
       double** B;
       B = new double* [rowsB];
       B[0] = new double [rowsB*colsB];
       for (int i = 1; i < rowsB; i++)
       {
          B[i] = B[i-1] + colsB;
       }


       for(int i = 0; i < rowsB; ++i)

       {
          for(int j = 0; j < colsB; ++j)

          {

             std::cout << "Enter element B" << i + 1 << j + 1 << " : ";
             std::cin >> B[i][j];

          }
       }


       assert(colsA == rowsB);


       double** C;
       C = new double* [rowsA];
       C[0] = new double [rowsA*colsB];
       for (int i = 1; i < rowsA; i++)
       {
          C[i] = C[i-1] + colsB;
       }


       for(int i = 0; i < rowsA; ++i)

       {
          for(int j = 0; j < colsB; ++j)
          {

             C[i][j]=0;

          }
       }


      for(int i = 0; i < rowsA; ++i)

       {
          for(int j = 0; j < colsB; ++j)

          {
             for(int k = 0; k < colsB; ++k)
             {
                C[i][j] += A[i][k] * B[k][j];

             }
          }
       }



       std::cout<< "Matrix C: " << std::endl;

       for(int i = 0; i < rowsA; ++i)

       {
          for(int j = 0; j < colsB; ++j)

          {

              std::cout << " " << C[i][j];

              if(j == colsB-1)

              {
                  std::cout << std::endl;

              }
          }
       }

       delete[] C[0];
       delete[] C;
       delete[] B[0];
       delete[] B;
       delete[] A[0];
       delete[] A;
     }
