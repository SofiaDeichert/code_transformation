int main ( ) { long long int t , n , c , i , j , p ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld" , & n ) ; long long int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%lld" , & a [ i ] ) ; c = 0 ; for ( i = 0 ; i < n ; i ++ ) { p = a [ i ] ; for ( j = i ; j < n ; j ++ ) { if ( a [ j ] >= p ) c ++ ; else break ; p = a [ j ] ; } } printf ( "%lld\n" , c ) ; } return 0 ; }