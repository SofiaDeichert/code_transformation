int GCD ( int x , int y ) { if ( y == 0 ) { return x ; } return GCD ( y , x % y ) ; } int main ( ) { int t , i , a , b , g , l ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d %d" , & a , & b ) ; g = GCD ( a , b ) ; l = ( int ) a * b / g ; printf ( "%d %d\n" , g , l ) ; } return 0 ; }