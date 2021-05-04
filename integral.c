
double integral( double (*f) ( double x ), double a, double b, double eps2 )
{
    unsigned n0 = 10;
    double p = 1 / 3;

    unsigned n = 2 * n0;
    double I_n, I_2n, abs_diff_I;
    double F_i;
    double F = 0;
    double x = a;
    double h = ( b - a ) / n;
    double F_2n = 0.5 * f( a );
    double F_n;

    for( int i = 1; i < n; ++i ){
            x = a + i * h;
            F_i = f( x );
            F_2n += F_i;
    }
    
    F_2n += 0.5 * f( b );
    I_2n = F_2n * h;

    do{
	F_n = F_2n;
	I_n = I_2n;

	h /= 2;
	n *= 2;
        for( int i = 1; i < n; i += 2 ){
	    x = a + i * h;
	    F_i = f( x );
	    F_2n += F_i;
        }
	I_2n = h * F_2n;
	
	abs_diff_I = I_2n - I_n;
	if( abs_diff_I < 0 ){
	    abs_diff_I *= -1;
	}

    } while( ( p * abs_diff_I ) >= eps2 );


    return I_2n;
}
