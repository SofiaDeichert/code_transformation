long long int fun ( long long int , long long int ) ; int main ( ) { int n , i ; long long int l , h , a , b ; scanf ( "%d" , & n ) ; for ( i = 1 ; i <= n ; i ++ ) { scanf ( "%lld %lld" , & a , & b ) ; h = fun ( a , b ) ; l = ( a * b ) / h ; printf ( "%lld %lld\n" , h , l ) ; } return 0 ; } long long int fun ( long long int a , long long int b ) { if ( b == 0 ) return a ; else return fun ( b , a % b ) ; }