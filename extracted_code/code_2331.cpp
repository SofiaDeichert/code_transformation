int n ; int * * a ; int * * cache , * * visit ; int max ( int c , int d ) { return c > d ? c : d ; } int max_path ( int i , int j ) { int t1 , t2 , t ; if ( i >= n ) return 0 ; if ( visit [ i ] [ j ] == 1 ) return cache [ i ] [ j ] ; else t1 = max_path ( i + 1 , j ) ; t2 = max_path ( i + 1 , j + 1 ) ; t = max ( t1 , t2 ) + a [ i ] [ j ] ; cache [ i ] [ j ] = t ; visit [ i ] [ j ] = 1 ; return t ; } void printm ( ) { int i , j ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) printf ( "%d\t" , a [ i ] [ j ] ) ; printf ( "\n" ) ; } } int main ( ) { int i , j , t , m , * op ; scanf ( "%d" , & t ) ; op = ( int * ) malloc ( t * sizeof ( int ) ) ; for ( m = 0 ; m < t ; m ++ ) { scanf ( "%d" , & n ) ; a = ( int * * ) malloc ( n * sizeof ( int * ) ) ; cache = ( int * * ) malloc ( n * sizeof ( int * ) ) ; visit = ( int * * ) malloc ( n * sizeof ( int * ) ) ; for ( i = 0 ; i < n ; i ++ ) { a [ i ] = ( int * ) malloc ( sizeof ( int ) * n ) ; cache [ i ] = ( int * ) malloc ( sizeof ( int ) * n ) ; visit [ i ] = ( int * ) malloc ( sizeof ( int ) * n ) ; } for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; visit [ i ] [ j ] = 0 ; cache [ i ] [ j ] = 0 ; } op [ m ] = max_path ( 0 , 0 ) ; } for ( i = 0 ; i < t ; i ++ ) printf ( "%d\n" , op [ i ] ) ; return 0 ; }