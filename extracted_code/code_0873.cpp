int main ( ) { int t , n , i , k , m , j ; long long int sum ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; k = 0 ; int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) { a [ i ] = 0 ; } sum = 0 ; for ( i = 0 ; i <= n ; i ++ ) { for ( j = 0 ; j < i ; j ++ ) { scanf ( "%d" , & a [ i ] ) ; } if ( a [ k ] > a [ k + 1 ] ) { sum = sum + a [ k ] ; } else { sum = sum + a [ k + 1 ] ; k ++ ; } } printf ( "%lld\n" , sum ) ; } return 0 ; }