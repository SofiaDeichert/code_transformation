int main ( ) { long int t ; scanf ( "%lu" , & t ) ; while ( t -- ) { unsigned long long int n , i , sum = 0 , k ; scanf ( "%llu" , & n ) ; scanf ( "%llu" , & k ) ; for ( i = 2 ; i <= n ; i ++ ) { unsigned long long int a [ n ] , j , max = - 99999 ; for ( j = 0 ; j < i ; j ++ ) { scanf ( "%llu" , & a [ j ] ) ; if ( max < a [ j ] ) max = a [ j ] ; } sum += max ; } printf ( "%llu\n" , sum ) ; } return 0 ; }