int a [ 100001 ] ; int main ( void ) { int t , n , i , j , c , x ; int s ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } for ( i = 0 , s = 0 ; i < n - 1 ; i ++ ) { for ( j = i + 1 , c = 0 ; j < n ; j ++ ) { if ( a [ j ] >= a [ j - 1 ] ) c ++ ; else { x = 1 ; break ; } } if ( x ) { s = s + ( c * ( c + 1 ) ) / 2 ; i = j - 1 ; } else s = s + c ; } printf ( "%d\n" , s + n ) ; } return 0 ; }