int main ( int argc , char * argv [ ] ) { long int t ; scanf ( "%ld" , & t ) ; while ( t -- ) { long int n ; long int mini = 0 ; scanf ( "%ld" , & n ) ; long int a [ n ] ; for ( int j = 0 ; j < n ; j ++ ) { scanf ( "%ld" , & a [ j ] ) ; if ( mini > a [ j ] ) mini = a [ j ] ; } long long int cost ; cost = mini * ( n - 1 ) ; printf ( "%lld" , cost ) ; } }