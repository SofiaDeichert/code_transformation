int main ( ) { int n , i ; scanf ( "%d\n" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { int a , b ; scanf ( "%d%d" , & a , & b ) ; int dup1 = a , dup2 = b ; if ( a < b ) { int t = a ; a = b ; b = t ; } while ( a % b != 0 ) { b = a % b ; a = b ; } printf ( "%d %d\n" , b , ( dup1 * dup2 / b ) ) ; } return 0 ; }