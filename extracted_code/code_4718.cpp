int maxsum ( int i , int j , int * * a , int p ) { if ( i == p - 1 ) return a [ i ] [ j ] ; int s1 = maxsum ( i + 1 , j , a , p ) ; int s2 = maxsum ( i + 1 , j + 1 , a , p ) ; if ( s1 > s2 ) return a [ i ] [ j ] + s1 ; else return a [ i ] [ j ] + s2 ; } int main ( ) { int n , p , * * a , i , j , s ; scanf ( "%d" , & n ) ; while ( n > 0 ) { s = 0 ; scanf ( "%d" , & p ) ; a = ( int * * ) malloc ( p * sizeof ( int * ) ) ; for ( i = 0 ; i < p ; i ++ ) { a [ i ] = ( int * ) malloc ( ( i + 1 ) * sizeof ( int ) ) ; } for ( i = 0 ; i < p ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; s = maxsum ( 0 , 0 , a , p ) ; printf ( "%d\n" , s ) ; n -- ; } return 0 ; }