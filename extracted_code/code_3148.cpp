long int gcd ( long int A , long int B ) ; int main ( ) { int T ; long int A , B ; scanf ( "%d" , & T ) ; if ( T < 1 || T > 1000 ) { return 0 ; } for ( int i = 0 ; i < T ; i ++ ) { scanf ( "%ld %ld" , & A , & B ) ; if ( A >= 1 && A <= 1000000 && B >= 1 && B <= 1000000 ) { long int x = gcd ( ( A > B ? A : B ) , ( A < B ? A : B ) ) ; printf ( "%ld %lli\n" , x , A * B / x ) ; } } return 0 ; } long int gcd ( long int big , long int small ) { int temp ; while ( small > 0 ) { temp = small ; small = big % small ; big = temp ; } return ( big ) ; }