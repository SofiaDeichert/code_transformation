typedef long long int lld ; int main ( void ) { int T ; scanf ( "%d" , & T ) ; while ( T -- ) { lld N ; scanf ( "%lld" , & N ) ; lld min ; long long int cost = 0 ; scanf ( "%lld" , & min ) ; lld i = N ; while ( -- i ) { lld temp ; scanf ( "%lld" , & temp ) ; min = ( lld ) small ( min , temp ) ; } cost = min * ( N - 1 ) ; printf ( "%lld\n" , cost ) ; } return 0 ; }