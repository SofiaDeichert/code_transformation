int min ( int a [ ] , int n ) { int i = 0 , j = 1 , s = 0 ; while ( n != 1 ) { if ( a [ i ] > a [ j ] ) { i += 2 ; s += a [ j ] ; } else { j ++ ; s += a [ i ] ; } n -- ; } return s ; } int main ( void ) { int a [ 100 ] , n , t ; scanf ( "%d" , & t ) ; while ( t > 0 ) { scanf ( "%d" , & n ) ; for ( int i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } int s = min ( a , n ) ; printf ( "%d\n" , s ) ; t -- ; } return 0 ; }