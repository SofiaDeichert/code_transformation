int getint ( ) { char n = 0 , c ; while ( c < 33 ) { c = getchar_unlocked ( ) ; } while ( c > 33 ) { n = n * 10 + c - '0' ; c = getchar_unlocked ( ) ; } return n ; } int main ( void ) { int t , n , i , j , arr [ 101 ] [ 101 ] ; t = getint ( ) ; while ( t -- ) { n = getint ( ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { arr [ i ] [ j ] = getint ( ) ; } } for ( i = n - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { arr [ i ] [ j ] += max ( arr [ i + 1 ] [ j ] , arr [ i + 1 ] [ j + 1 ] ) ; } } printf ( "%d\n" , arr [ 0 ] [ 0 ] ) ; } return 0 ; }