int main ( ) { int t , n , curr , curi , sum , * arr , * crr , i , a , b , c , d , e , ap ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; ap = ( n * ( n + 1 ) ) / 2 ; arr = ( int * ) calloc ( ap * n , sizeof ( int ) ) ; crr = arr ; i = 1 ; sum = 0 ; curr = 1 ; curi = 0 ; while ( ( i ++ ) <= ap ) { scanf ( "%d" , & ( * crr ) ) ; crr ++ ; } while ( 1 ) { sum = sum + arr [ curi ] ; if ( curr < ( n - 1 ) ) { a = arr [ curi + curr ] ; b = arr [ curi + curr + 1 ] ; c = arr [ curi + curr + curr + 1 ] ; d = arr [ curi + curr + curr + 2 ] ; e = arr [ curi + curr + curr + 3 ] ; if ( ( ( a > b ) && ( ( a + c ) > ( b + e ) ) ) || ( ( a < b ) && ( ( a + c ) > ( b + d ) ) && ( ( a + c ) > ( b + e ) ) ) ) { curi = curi + curr ; curr ++ ; } else { curi = curi + curr + 1 ; curr ++ ; } } else if ( curr == ( n - 1 ) ) { a = arr [ curi + curr ] ; b = arr [ curi + curr + 1 ] ; if ( a > b ) { curi = curi + curr ; curr ++ ; } else { curi = curi + curr + 1 ; curr ++ ; } } else break ; } printf ( "\n%d" , sum ) ; } }