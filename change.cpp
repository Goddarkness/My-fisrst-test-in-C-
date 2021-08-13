#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Matrix
{
private :
    vector <double> a = {0};
    int m, n ;

public:
    void  readfile( char file[]);  // 从file中读矩阵
    void outputfile( char file[]);  //输出矩阵于file中
    void print();                   // 在屏幕中输出矩阵
    void add( Matrix b , Matrix c);   // 将两个矩阵相加
    void mulitiply ( Matrix b , Matrix c );  //将两个矩阵相乘
    Matrix operator +( Matrix b);    // 重载操作符+ ， 使"+"能让两个矩阵相加
} ;

void Matrix::print()
{
    for ( int i = 0 ; i < m*n ; i++)
    {
        cout << a[i] << " ";
    if ( (i+1)%n == 0 )
        cout << "\n";
    }
}

void Matrix ::add(Matrix b , Matrix c)
{
      if ( b.m != c.m || b.n != c.n)
      {
          cout << " 矩阵规模不等，无法进行计算!" << endl;
      }
      for ( int i =0 ; i < b.m*b.n; i++)
        a[i] = b.a[i] + c.a[i];
        m = b.m;
        n = b.n;
}

void Matrix::mulitiply(Matrix b , Matrix c)
{
    if ( b.n != c.m)
    {
        cout << "不符合运算条件，不能计算" << endl;

    }
    for ( int i =0 ; i < b.m ; i++)
    {
        for ( int j =0 ; j < c.n ; j++)
            for ( int  k =0 ; k < b.n ; k++)
            a[i*c.n+j] =  a[i*c.n+j]+b.a[i*b.n+k]*c.a[k*b.n+j];
    }
    m = b.m;
    n = c.n;

}
void Matrix :: readfile( char file[])

{
     FILE *fp;
    char c;
     m = 0 , n=0;
    if ( (fp = fopen( file,"r")) == NULL)
    {
        printf("cannot open the file\n");
        exit(0);
    }
    int i =0;
    while( (c = fgetc(fp)) != EOF )
     {
         if (c!=32 && c !='\n' )
             a[i] = a[i]*10+ (c - '0');
         if  ( c == 32  )
           {
            a.push_back(0);
            i++;
           }
         if ( c == '\n')
         {
             a.push_back(0);
             i++;
             m++;
         }
     }
     a.pop_back();

     n = i/m;
    if ( fclose(fp))
    {
        printf("cannot close this file\n");
        exit(0);
    }
}
void Matrix::outputfile( char file[])
{
    FILE *fp;
    if ( (fp = fopen(file,"w")) == NULL)
    {
        printf("cannot open the file\n");
        exit(0);
    }

   for ( int i =0 ; i < m*n ;i++)
   {
      // fputs(gcvt(a[i],10,b), fp );
       fprintf(fp, "%lf",a[i]);
       fputc ('\t',fp);
       if ( (i+1) %n == 0)
        fputc('\n',fp);

   }

      if ( fclose(fp))
    {

        printf("cannot close this file\n");
        exit(0);
    }
}
Matrix Matrix ::operator+( Matrix b)
{
     Matrix c;
      for ( int i =0 ; i < b.m*b.n; i++)
        c.a[i] = b.a[i] + a[i];
       c.m = b.m;
       c.n = b.n;
       return c;
}


int main()
{
    Matrix matrix1 ;
    Matrix matrix2 ;
    Matrix matrix3 ;
    matrix1.readfile("H:\\test.txt");
    matrix1.print();
  //  matrix2.readfile("H:\\test2.txt");
  //  matrix3.mulitiply(matrix1,matrix2);
  //  matrix3 = matrix1+matrix2;
  //  matrix3.outputfile("H:\\test3.txt");

    return 0;
}
