int main ( ) { int T , i , j , N , k ; scanf ( "%d" , & T ) ; int maxi [ T ] ; for ( k = 0 ; k < T ; k ++ ) maxi [ k ] = 0 ; for ( k = 0 ; k < T ; k ++ ) { scanf ( "%d" , & N ) ; if ( N > 100 ) return 0 ; int a [ N ] ; for ( i = 0 ; i < N ; i ++ ) a [ i ] = 0 ; for ( i = 0 ; i < N ; i ++ ) { int b [ i + 1 ] ; for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & b [ j ] ) ; if ( b [ j ] >= 100 ) return 0 ; } for ( j = 0 ; j <= i ; j ++ ) { if ( b [ j ] < b [ j + 1 ] && j + 1 < i ) a [ j ] = a [ j ] + b [ j + 1 ] ; else a [ j ] = a [ j ] + b [ j ] ; } } for ( i = 0 ; i < N ; i ++ ) { if ( a [ i ] > maxi [ k ] ) maxi [ k ] = a [ i ] ; } } for ( k = 0 ; k < T ; k ++ ) printf ( "%d\n" , maxi [ k ] ) ; return 0 ; }