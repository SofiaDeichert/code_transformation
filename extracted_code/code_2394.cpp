inline int getInt ( ) { char c ; int val = 0 ; while ( ! isdigit ( c = getchar_unlocked ( ) ) ) ; do { val = val * 10 + ( c - '0' ) ; } while ( isdigit ( c = getchar_unlocked ( ) ) ) ; return val ; } int getInt ( ) ; int main ( ) { int t = getInt ( ) ; unsigned long long int result [ MAX ] ; int i ; for ( i = 0 ; i < t ; i ++ ) { int n = getInt ( ) ; int j , min = getInt ( ) ; for ( j = 1 ; j < n ; j ++ ) { int a = getInt ( ) ; if ( a < min ) min = a ; } result [ i ] = ( unsigned long long ) min * ( n - 1 ) ; } for ( i = 0 ; i < t ; i ++ ) printf ( "%llu\n" , result [ i ] ) ; return 0 ; }