int arr [ MAX ] [ MAX ] ; int cache [ 100 ] [ 100 ] ; int sum ( int , int ) ; int max ( int , int ) ; void initialise ( ) ; int L ; int main ( ) { int T ; int i , j , max ; scanf ( "%d" , & T ) ; while ( T -- ) { initialise ( ) ; scanf ( "%d" , & L ) ; for ( i = 0 ; i < L ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & arr [ i ] [ j ] ) ; max = sum ( 0 , 0 ) ; printf ( "%d\n" , max ) ; } return 0 ; } int sum ( int i , int j ) { int t1 , t2 , t3 ; if ( i >= L ) return 0 ; if ( cache [ i ] [ j ] != 0 ) return cache [ i ] [ j ] ; t1 = sum ( i + 1 , j ) ; t2 = sum ( i + 1 , j + 1 ) ; t3 = arr [ i ] [ j ] + max ( t1 , t2 ) ; cache [ i ] [ j ] = t3 ; return t3 ; } int max ( int i , int j ) { if ( i > j ) return i ; return j ; } void initialise ( ) { int i , j ; for ( i = 0 ; i < 100 ; i ++ ) for ( j = 0 ; j < 100 ; j ++ ) cache [ i ] [ j ] = 0 ; }