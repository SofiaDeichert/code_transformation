int main ( ) { int t , n , i ; long long int a [ 50001 ] ; long long int large , small , count = 0 ; scanf ( "%d" , & t ) ; while ( t -- ) { count = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & a [ i ] ) ; } large = a [ 1 ] ; small = a [ 0 ] ; if ( n == 2 ) { if ( small > large ) small = large ; printf ( "%lld\n" , small ) ; } else { for ( i = 1 ; i < n ; i ++ ) { if ( small > large ) { small = large ; } count = count + small ; large = a [ i + 1 ] ; } printf ( "%lld\n" , count ) ; } } }