int HCF ( int , int ) ; int LCM ( int , int ) ; int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int a , b , x , y ; scanf ( "%d%d" , & a , & b ) ; x = HCF ( a , b ) ; y = LCM ( a , b ) ; printf ( "%d  %d\n" , x , y ) ; } return 0 ; } int HCF ( int n , int m ) { if ( n > m ) return HCF ( n - m , m ) ; else if ( n < m ) return HCF ( n , m - n ) ; else if ( n == m ) return n ; } int LCM ( int p , int q ) { int i = 1 ; if ( p > q ) { while ( ( p * i ) % q != 0 ) i ++ ; p = p * i ; return p ; } else if ( q > p ) { while ( ( q * i ) % p != 0 ) i ++ ; q = q * i ; return q ; } else if ( p == q ) return p ; }