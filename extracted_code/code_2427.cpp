typedef long long ll ; int main ( ) { ll t , n , x , cost , i , ss ; scanf ( "%ld" , & t ) ; ll small ; int a [ 50005 ] ; ll test , j = 0 , k ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%lld" , & n ) ; for ( ss = 0 ; ss < n ; ss ++ ) { scanf ( "%d " , & a [ ss ] ) ; } small = a [ 0 ] ; for ( j = 0 ; j < n ; j ++ ) { if ( a [ j ] < small ) { small = a [ j ] ; } } ll c = small * ( n - 1 ) ; printf ( "%lld\n" , c ) ; } return 0 ; }