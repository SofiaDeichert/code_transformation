int main ( void ) { int test , i ; printf ( "enter the number of test cases" ) ; scanf ( "%d" , & test ) ; long * num1 = ( long * ) malloc ( test * sizeof ( long ) ) ; long * num2 = ( long * ) malloc ( test * sizeof ( long ) ) ; long * gcd = ( long * ) malloc ( test * sizeof ( long ) ) ; long * lcm = ( long * ) malloc ( test * sizeof ( long ) ) ; for ( i = 0 ; i < test ; i ++ ) { printf ( "\n" ) ; scanf ( "%ld" , & num1 [ i ] ) ; scanf ( "%ld" , & num2 [ i ] ) ; } for ( i = 0 ; i < test ; i ++ ) { long temp1 = num1 [ i ] ; long temp2 = num2 [ i ] ; while ( num1 [ i ] != num2 [ i ] ) { if ( num1 [ i ] > num2 [ i ] ) num1 [ i ] = num1 [ i ] - num2 [ i ] ; else if ( num2 [ i ] > num1 [ i ] ) num2 [ i ] = num2 [ i ] - num1 [ i ] ; } gcd [ i ] = num1 [ i ] ; lcm [ i ] = ( temp1 * temp2 ) / gcd [ i ] ; num1 [ i ] = temp1 ; num2 [ i ] = temp2 ; } for ( i = 0 ; i < test ; i ++ ) { printf ( "\n" ) ; printf ( "%ld %ld" , gcd [ i ] , lcm [ i ] ) ; } return 0 ; }