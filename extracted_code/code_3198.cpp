int main ( ) { int T , N , j , i ; scanf ( " %d" , & T ) ; if ( T >= 1 && T <= 5 ) { for ( j = 0 ; j < T ; j ++ ) { scanf ( " %d" , & N ) ; if ( N >= 1 && N <= 100000 ) { int a [ N ] , sum = 0 , k ; for ( i = 0 ; i < N ; i ++ ) scanf ( " %d" , & a [ i ] ) ; for ( i = 0 ; i < N ; i ++ ) { for ( k = i + 1 ; k < N ; k ++ ) { if ( a [ i ] == a [ k ] ) break ; } if ( k == N ) sum = sum + 1 ; } for ( i = 0 ; i < N - 1 ; i ++ ) { for ( k = i + 1 ; k < N ; k ++ ) { if ( a [ k ] >= a [ k - 1 ] ) sum = sum + 1 ; else break ; } } printf ( "%d\n" , sum ) ; } } } }