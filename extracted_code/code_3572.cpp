int main ( ) { int n ; scanf ( "%d" , & n ) ; while ( n -- ) { int m , x , tmp , total = 1 , cnt = 1 ; scanf ( "%d" , & m ) ; scanf ( "%d" , & x ) ; tmp = x ; m -- ; while ( m -- ) { scanf ( "%d" , & x ) ; if ( tmp <= x ) cnt ++ ; else cnt = 1 ; tmp = x ; total += cnt ; } printf ( "%d\n" , total ) ; } return 0 ; }