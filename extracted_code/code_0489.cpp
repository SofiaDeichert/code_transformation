int greater ( int a , int b ) { if ( a >= b ) { return a ; } else { return b ; } } int main ( ) { int n , t , i , r , s = 0 , c = 0 , d [ 109 ] [ 109 ] ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { s = 0 ; scanf ( "%d" , & t ) ; for ( r = 0 ; r < t ; r ++ ) { for ( c = 0 ; c <= r ; c ++ ) { scanf ( "%d" , & d [ r ] [ c ] ) ; } } for ( r = t - 2 ; r >= 0 ; r -- ) { for ( c = 0 ; c <= r ; c ++ ) { d [ r ] [ c ] = d [ r ] [ c ] + greater ( d [ r + 1 ] [ c ] , d [ r + 1 ] [ c + 1 ] ) ; } } printf ( "%d\n" , d [ 0 ] [ 0 ] ) ; } return 0 ; }