int main ( ) { int t , n , i , a [ 100000 ] , j , c ; scanf ( "%lld" , & t ) ; while ( t -- ) { c = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; c = n ; for ( i = 0 ; i < n - 1 ; i ++ ) { for ( j = i + 1 ; j < n ; j ++ ) { if ( a [ i ] > a [ j ] ) break ; } if ( j == n ) c ++ ; } printf ( "%d\n" , c ) ; } return 0 ; }