int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long int n , i , m , ans = 0 , j , temp ; scanf ( "%ld" , & n ) ; long int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%ld" , & a [ i ] ) ; } for ( i = 0 ; i < n - 1 ; i ++ ) { for ( j = i ; j < n ; j ++ ) { if ( a [ i ] > a [ j ] ) { temp = a [ i ] ; a [ i ] = a [ j ] ; a [ j ] = temp ; } } } printf ( "%ld\n" , ( n - 1 ) * a [ 0 ] ) ; } }