int main ( ) { int t , a , b , i , j ; scanf ( "%d" , & t ) ; if ( t <= 1000 && t >= 1 ) while ( t -- ) { scanf ( "%d%d" , & a , & b ) ; if ( a <= 1000000 && a >= 1 && b <= 1000000 && b >= 1 ) { if ( a > b ) i = b ; else i = a ; for ( ; ; i -- ) { if ( ( a % i == 0 ) && ( b % i == 0 ) ) printf ( "%d " , i ) ; break ; } j = a * b / i ; printf ( "%d\n" , j ) ; } else break ; } return 0 ; }