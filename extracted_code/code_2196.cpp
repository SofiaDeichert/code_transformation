unsigned find ( unsigned long int a [ ] , unsigned int n ) { unsigned int min ; unsigned int i ; unsigned int j ; min = 10 , 000 ; i = 0 ; while ( i < n ) { if ( min >= a [ i ] ) { min = a [ i ] ; j = i ; } i ++ ; } return min ; } int main ( ) { unsigned int i ; unsigned int t ; unsigned int p ; unsigned int j ; unsigned int n ; unsigned int cost ; unsigned int a [ 10 ] ; scanf ( "%u" , & t ) ; while ( t > 0 ) { scanf ( "%u" , & p ) ; if ( p == 1 ) { break ; } i = 0 ; cost = 0 ; while ( i < p ) { scanf ( "\t%u" , & a [ i ] ) ; i ++ ; } n = p ; j = find ( a , n ) ; j = j * ( n - 1 ) ; printf ( "\n%u" , j ) ; t -- ; } return 0 ; }