int main ( ) { int a , b , n , i , j = 0 , k , lcm = 1 , gcd = 1 , x , y , p , q ; int s [ 10000000 ] ; int count [ 10000000 ] = { 0 } ; scanf ( "%d\n" , & n ) ; for ( y = 0 ; y < n ; y ++ ) { scanf ( "%d %d\n" , & a , & b ) ; p = a ; q = b ; if ( a > b ) k = a ; else k = b ; for ( i = 2 ; i <= k ; i ++ ) { if ( a % i == 0 || b % i == 0 ) { while ( a % i != 0 && b % i != 0 ) { if ( a % i == 0 ) a = a / i ; else b = b / i ; count [ j ] = count [ j ] + 1 ; } s [ j ] = i ; j ++ ; } } while ( x >= 0 ) { x = j - 1 ; if ( p % s [ x ] == 0 && q % s [ x ] == 0 ) { gcd = gcd * s [ x ] ; lcm = lcm * s [ x ] * count [ x ] ; } else if ( p % s [ x ] != 0 && q % s [ x ] == 0 || p % s [ x ] == 0 && q % s [ x ] != 0 ) lcm = lcm * s [ x ] * count [ x ] ; x -- ; } printf ( "%d %d\n" , gcd , lcm ) ; } return 0 ; }