int i , j , k , T ; long long unsigned int a , n ; int main ( ) { scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%llu" , & n ) ; long long unsigned int N [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%llu" , & N [ i ] ) ; } a = 100001 ; for ( j = 0 ; j < n ; j ++ ) { if ( a > N [ j ] ) { a = N [ j ] ; } } printf ( "%llu" , a * ( n - 1 ) ) ; } }