int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long n , i , j , count = 0 , k ; scanf ( "%ld" , & n ) ; long arr [ n ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%ld" , & arr [ i ] ) ; for ( i = 0 ; i < n ; i ++ ) { k = arr [ i ] ; for ( j = i ; j < n ; j ++ ) { if ( arr [ j ] >= k ) { count ++ ; k = arr [ j ] ; } else k = 99999999999999 ; } } printf ( "%ld\n" , count ) ; } }