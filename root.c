

double root( double (*f1)( double x ), double (*f2)( double x ),
             double a, double b,
             double eps1,
             double (*f1_1)( double x ), double (*f2_1)( double x )
           )
{
    /* рассматриваем функцию F(x) = f1(x) - f2(x) */
    /* определение монотонности функции F */
    double F_a = f1( a ) - f2( a );
    double F_b = f1( b ) - f2( b );

    /* определение направления выпуклости функции F */
    double mid = ( a + b ) / 2;
    double F_mid = f1( mid ) - f2( mid );
    double F_avg = ( F_a + F_b ) / 2;
    double root;
    double c1, c2;

    int i = 0;
    if( ( ( F_a < 0 ) && ( F_mid < F_avg ) ) /* F возрастает и выпукла вниз */
        ||
        ( ( F_a > 0 ) && ( F_mid > F_avg ) ) /* F убывает и выпукла вверх */
      )
    { /* F' и F'' одного знака */
	
        double x_left = a;
        double F_left = F_a;
        double x_right = b;
        double F_right = F_b;
        double F_1_right = f1_1( b ) - f2_1( b );

	
        do{
            ++i;
	    /* метод хорд приближения к корню слева */

            /* точка пересечения хорды с осью абсцисс*/
            c1 = ( x_left * F_b - b * F_left ) / ( F_b - F_left );
            double F_c1 = f1( c1 ) - f2( c1 );
            x_left = c1;
            F_left = F_c1;

            /* метод касательных приближения к корню справа */

            c2 = x_right - F_right / F_1_right;
            double F_c2 = f1 ( c2 ) - f2( c2 );
            x_right = c2;
            F_right = F_c2;
            F_1_right = f1_1( x_right ) - f2_1( x_right );

        } while( ( c2 - c1 ) >= eps1 );
    } else /* F возрастает и выпукла вверх или F убывает и выпукла вниз */
    { /* F' и F'' разных знаков */
        double x_right = b;
        double F_right = F_b;
        double x_left = a;
        double F_left = F_a;
        double F_1_left = f1_1( x_left ) - f2_1( x_left );

        do{
	    ++i;
            /* метод хорд приближения к корню справа */

            /* точка пересечения хорды с осью абсцисс */
            c1 = ( a * F_right - x_right * F_a ) / ( F_right - F_a );
            double F_c1 = f1( c1 ) - f2( c1 );
            x_right = c1;
            F_right = F_c1;

            /* метод касательных приближения к корню слева */

            c2 = x_left - F_left / F_1_left;
            double F_c2 = f1 ( c2 ) - f2( c2 );
            x_left = c2;
            F_left = F_c2;
            F_1_left = f1_1( x_left ) - f2_1( x_left );

        } while( ( c1 - c2 ) >= eps1 );
    }

    root = ( c1 + c2 ) / 2;

    return root;
}
