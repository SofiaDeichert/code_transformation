int GCD ( int a , int b ) { int divisor , D , aux ; divisor = a > b ? b : a ; D = a > b ? a : b ; while ( 1 ) { if ( ( aux = D % divisor ) == 0 ) { return divisor ; } else { D = divisor ; divisor = aux ; } } } int main ( ) { int x , y , i , j , T , lcm ; scanf ( "%d" , & T ) ; scanf ( "%d%d" , & x , & y ) ; for ( i = 0 ; i < T ; i ++ ) { j = GCD ( x , y ) ; lcm = x * y / j ; printf ( "%d %d\n" , j , lcm ) ; } return 0 ; }