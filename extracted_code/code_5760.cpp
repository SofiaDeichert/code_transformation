int main ( void ) { long int a = 10000000 , b , c , t , n , i , j ; scanf ( "%ld" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%ld" , & n ) ; for ( j = 0 ; j < n ; j ++ ) { scanf ( "%ld" , & b ) ; if ( a > b ) a = b ; } c = a * ( n - 1 ) ; printf ( "%ld\n" , c ) ; } return 0 ; }