int gcd ( int , int ) ; int main ( ) { int t , i ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { int a , b ; long long int n , lcm ; scanf ( "%d%d" , & a , & b ) ; n = gcd ( a , b ) ; lcm = a * b / n ; printf ( "%lld " , n ) ; printf ( "%lld\n" , lcm ) ; } } int gcd ( int x , int y ) { if ( x == 0 ) return y ; else if ( x > y ) { if ( x % y == 0 ) return y ; else return gcd ( y , x % y ) ; } else { if ( y % x == 0 ) return x ; else return ( x , y % x ) ; } }