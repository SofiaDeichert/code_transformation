int main ( void ) { long long int n , t , i , temp , count , num , ans , flag ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld" , & n ) ; count = 0 ; ans = 0 ; num = - 1 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & temp ) ; if ( temp > num ) { num = temp ; count ++ ; flag = 0 ; } else { ans += ( ( count * ( count + 1 ) ) / 2 ) ; count = 1 ; flag = 1 ; } num = temp ; } ans += ( ( count * ( count + 1 ) ) / 2 ) ; printf ( "%lld\n" , ans ) ; } return 0 ; }