int i ; int main ( ) { long long int t , a , b , v1 , v2 ; scanf ( "%d" , & t ) ; printf ( "\n" ) ; while ( t -- ) { scanf ( "%d %d" , & a , & b ) ; v1 = a <= b ? a : b ; v2 = a >= b ? a : b ; v1 = v1 <= ( v2 - v1 ) ? v1 : ( v2 - v1 ) ; for ( i = v1 ; i >= 1 ; i -- ) { if ( ( a % i == 0 ) && ( b % i == 0 ) ) { printf ( "%d" , i ) ; break ; } } printf ( " %d\n" , ( a * b ) / i ) ; } }