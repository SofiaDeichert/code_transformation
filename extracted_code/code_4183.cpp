int main ( void ) { int n , i , r , c , sum , max = 0 ; scanf ( "%d" , & n ) ; while ( n ) { scanf ( "%d" , & i ) ; int arr [ i ] [ i ] ; for ( r = 0 ; r < i ; r ++ ) { for ( c = 0 ; c <= r ; c ++ ) { scanf ( "%d" , & arr [ r ] [ c ] ) ; } } for ( r = i - 1 ; r > 0 ; r -- ) { for ( c = 1 ; c > 0 ; c -- ) { sum = arr [ r ] [ c ] + arr [ r ] [ c - 1 ] + arr [ r - 1 ] [ c - 1 ] ; if ( sum > max ) max = sum ; } } printf ( "%d\n" , max ) ; n -- ; } return 0 ; }