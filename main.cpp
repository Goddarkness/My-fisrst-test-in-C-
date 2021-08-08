#include <iostream>
#include <fstream>

using namespace std;
class Matrix
{
private :
    int m, n ;
    double a[1000];
public:
    void  readfile( char file[]);
    void outputfile( char file[]);
    void print();
    void add( Matrix b , Matrix c);
    void mulitiply ( Matrix b , Matrix c );
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
            i++;
           }
         if ( c == '\n')
         {
             i++;
             m++;
         }
     }

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

int main()
{
    Matrix matrix1 ;
    Matrix matrix2 ;
    Matrix matrix3 ;
    matrix1.readfile("H:\\test.txt");
    matrix2.readfile("H:\\test2.txt");
    matrix3.mulitiply(matrix1,matrix2);
    matrix3.outputfile("H:\\test3.txt");

    return 0;
}
