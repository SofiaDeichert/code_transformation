void cost ( long long int [ ] , long long int ) ; int main ( ) { long long int i , no , n ; long long int a [ 10000 ] ; scanf ( "%lld" , & no ) ; for ( i = 0 ; i < no ; i ++ ) { scanf ( "%lld" , & n ) ; cost ( a , n ) ; } return 0 ; } void cost ( long long int a [ ] , long long int n ) { long long int min , j , cst ; for ( j = 0 ; j < n ; j ++ ) { scanf ( "%lld" , & a [ j ] ) ; } min = 109876 ; for ( j = 0 ; j < n ; j ++ ) { if ( a [ j ] < min ) min = a [ j ] ; } cst = ( unsigned long long ) ( n - 1 ) * min ; printf ( "%llu" , cst ) ; return ; }