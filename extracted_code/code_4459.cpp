int hcf ( int j , int k ) ; int main ( ) { int n , a , b , u , lcm ; scanf ( "%d" , & n ) ; while ( n != 0 ) { scanf ( "%d%d" , & a , & b ) ; u = hcf ( a , b ) ; lcm = ( a * b ) / u ; printf ( "%d %d" , u , lcm ) ; n -- ; } return 0 ; } int hcf ( int j , int k ) { if ( j == 0 ) { return k ; } while ( k != 0 ) { if ( j > k ) { j = j - k ; } else { k = k - j ; } } return j ; }