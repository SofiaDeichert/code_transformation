static inline int sum ( int * a , int n ) ; int main ( ) { int * a ; int * s ; int n , i , j , t ; scanf ( "%d" , & t ) ; s = ( int * ) malloc ( t * sizeof ( int ) ) ; for ( j = 0 ; j < t ; j ++ ) { scanf ( "%d" , & n ) ; a = ( int * ) malloc ( n * ( n + 1 ) / 2 * sizeof ( int ) ) ; for ( i = 0 ; i < n * ( n + 1 ) / 2 ; i ++ ) scanf ( "%d" , a + i ) ; * ( s + j ) = sum ( a , n ) ; free ( a ) ; } for ( j = 0 ; j < t ; j ++ ) printf ( "\n%d" , * ( s + j ) ) ; return 0 ; } static inline int sum ( int * a , int n ) { int i ; if ( n == 1 ) return * a ; else { for ( i = ( n * ( n - 1 ) / 2 ) - 1 ; i >= ( n - 1 ) * ( n - 2 ) / 2 ; i -- ) * ( a + i ) = * ( a + i ) + ( * ( a + i + n ) >= * ( a + i + n - 1 ) ? * ( a + i + n ) : * ( a + i + n - 1 ) ) ; return ( sum ( a , n - 1 ) ) ; } }