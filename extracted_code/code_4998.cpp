main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int a , b ; scanf ( "%d %d" , & a , & b ) ; printf ( "%d %d\n" , gcd ( a , b ) , lcm ( a , b ) ) ; } } int gcd ( int x , int y ) { if ( x == 1 && y == 1 ) return ( 1 ) ; if ( x == y ) return ( x ) ; if ( x > y ) return gcd ( x - y , y ) ; return gcd ( x , y - x ) ; } int lcm ( int x , int y ) { int i , max ; max = x > y ? x : y ; for ( i = max ; i <= x * y ; i ++ ) { if ( i % x == 0 && i % y == 0 ) break ; } return ( i ) ; }