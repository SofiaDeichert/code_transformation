int main ( ) { int t , n , i , j ; scanf ( "%d\n" , & t ) ; while ( t -- ) { scanf ( "%d\n" , & n ) ; int a [ n ] [ n ] ; int r , c , k = 1 ; for ( i = 0 ; i < k && k < n ; i ++ ) { for ( j = 0 ; j < k ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } long int sum = a [ 0 ] [ 0 ] ; k = 0 , r = 0 , c = 0 ; while ( k != ( n - 1 ) ) { if ( a [ r + 1 ] [ c ] > a [ r + 1 ] [ c + 1 ] ) { sum += a [ r + 1 ] [ c ] ; r = r + 1 ; } else { sum += a [ r + 1 ] [ c + 1 ] ; r = r + 1 ; c = c + 1 ; } k ++ ; } printf ( "%ld\n" , sum ) ; } return 0 ; }