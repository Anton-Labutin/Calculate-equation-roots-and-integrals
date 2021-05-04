
#include "file.h"


double (*ptr_f1)( double x );
double (*ptr_f2)( double x );

double F( double x )
{
	return f2( x ) - f1( x );
}

int main( int argc, char* argv[] )
{
    // f1(x) = 0.6 * x + 3
    // f2(x) = ( x - 2 ) ^ 3 - 1
    // f3(x) = 3 / x

   char *print_x_12 = "-x12";
   char *print_x_13 = "-x13";
   char *print_x_23 = "-x23";
   char *print_x = "-x";

   char *print_n_12 = "-n12";
   char *print_n_13 = "-n13";
   char *print_n_23 = "-n23";
   char *print_n = "-n";

   char *print_help = "-help";
	
   char *print_root = "-r";
   char *print_integral = "-i";

   if( argc > 1 ){
	int k = 0;
	if( ! strcmp( print_x, argv[1] ) ){
	    	k = 1;
    	}
   	if( k || ! strcmp( print_x_12, argv[1] ) ){
	     printf( "%f\n", root( f1, f2, 3.5, 4.0, f1_1, f2_1 );		     
	}
	if( k || ! strcmp( print_x_13, argv[1] ) ){
		printf( "%f\n", root( f1, f3, -6.0, -5.5, f1_1, f3_1 );
		printf( "%f\n", root( f1, f3,  0.5, 1.0, f1_1, f3_1 );
	}
	if( ! strcmp( print_x_23, argv[1] ) ){
		printf( "%f\n", root( f2, f3, -0.5, 0.0, f2_1, f3_1 );
		printf( "%f\n", root( f2, f3,  3.0, 3.5, f2_1, f3_1 );
	}
	if( ! strcmp( print_n_12, argv[1] ){

   }


   double a, b;
   double I;
   double eps = 0.0001;
   
   double a1, b1;
   double eps1 = 1e-6;
   double eps2 = 1e-6;
   
   //do{

   //eps1 /= 2;
   //eps2 /= 2;

   // integral ( f1( x ) - f3( x ) ) from a to b
   a1 = -6.0;
   b1 = -5.5;
   a = root( f1, f3, a1, b1, eps1, f1_1, f3_1 );
   
   a1 = -0.5;
   b1 =  0.0;
   b = root( f2, f3, a1, b1, f2_1, f3_1 );
	
   ptr_f1 = f3;
   ptr_f2 = f1;
   I = integral( F, a, b, eps2 );

   // integral ( f1( x ) - f2( x ) ) from a to b
   a = b;
   a1 = 0.5;
   b1 = 1.0;
   b = root( f1, f3, a1, b1, f1_1, f3_1 );
   
   ptr_f1 = f2;
   ptr_f2 = f1;
   I += integral( F, a, b, eps2 );

   // integral ( f3( x ) - f2( x ) ) from a to b
   a = b;
   a1 = 3.0;
   b1 = 3.5;
   b = root( f2, f3, a1, b1, f2_1, f3_1 );

   ptr_f1 = f2;
   ptr_f2 = f3;
   I += integral( F, a, b, eps2 );

   //}while( );
   printf( "%f\n", I );


   return 0;
}
