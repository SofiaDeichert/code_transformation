int gcd ( int a , int b ) { if ( a % b == 0 ) return b ; else return gcd ( b , a % b ) ; } int lcm ( int a , int b ) { int min = ( a > b ) ? a : b ; while ( 1 ) { if ( min % a == 0 && min % b == 0 ) { return min ; } min ++ ; } } void main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int a , b , g , l ; scanf ( "%d%d" , & a , & b ) ; g = gcd ( a , b ) ; l = lcm ( a , b ) ; printf ( "%d %d\n" , g , l ) ; } }