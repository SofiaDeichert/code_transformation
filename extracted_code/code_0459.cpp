int main ( ) { int t , i ; long long int a , b ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%lld%lld" , & a , & b ) ; int temp ; long long int x = a , y = b ; while ( a != b ) { if ( a > b ) a = a - b ; else b = b - a ; } printf ( "%d " , a ) ; printf ( "%d\n" , ( x * y / a ) ) ; } return 0 ; }