int main ( ) { int t , n , s , i , size , k , j ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d" , & n ) ; int a [ n ] ; size = n ; for ( j = 0 ; j < n ; j ++ ) scanf ( "%d" , & a [ j ] ) ; s = 0 ; while ( size != 1 ) { if ( a [ i ] >= a [ i + 1 ] ) { s += a [ i + 1 ] ; a [ i ] = a [ i + 1 ] ; } else { s += a [ i ] ; } for ( k = 1 ; k < n ; k ++ ) { a [ k ] = a [ k + 1 ] ; } size -- ; } printf ( "%d" , s ) ; } return 0 ; }