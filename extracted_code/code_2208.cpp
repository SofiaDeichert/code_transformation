int main ( ) { long long int n , t , ar [ 100000 ] , i , j , c ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld" , & n ) ; c = 0 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & ar [ i ] ) ; } for ( i = 0 ; i < n ; i ++ ) { for ( j = i ; j < n ; j ++ ) { if ( ar [ j + 1 ] >= ar [ j ] ) { c ++ ; } else break ; } } printf ( "%lld\n" , c + n ) ; } return 0 ; }