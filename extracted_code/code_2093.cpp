int a [ 50000 ] ; int main ( ) { int t , i , n , j , s , b ; long long int c ; scanf ( "%d" , & t ) ; for ( i = 1 ; i <= t ; i ++ ) { scanf ( "%d" , & n ) ; s = 0 ; for ( j = 0 ; j < n ; j ++ ) { scanf ( "%d" , & a [ j ] ) ; } b = a [ 0 ] ; for ( j = 1 ; j < n ; j ++ ) { if ( b > a [ j ] ) { b = a [ j ] ; } } c = b * ( n - 1 ) ; printf ( "%llu\n" , c ) ; } return 0 ; }