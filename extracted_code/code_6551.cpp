int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int a , b , st , nd , rem ; scanf ( "%d %d" , & a , & b ) ; if ( a > b ) { st = a ; nd = b ; } else if ( b > a ) { st = b ; nd = a ; } rem = st % nd ; while ( rem != 0 ) { st = nd ; nd = rem ; rem = st % nd ; } printf ( "%d " , nd ) ; printf ( "%d\n" , a * b / nd ) ; } }