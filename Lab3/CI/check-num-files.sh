#!/bin/bash

result=$(ls Lab3/ | grep -e 'adjmult' -e 'codes' -e 'lib' -e 'pascal' -e 'primes' -v | wc -l)

if (( $result > 0 )); then
    echo "Failure. There is an extra file or folder present in Lab3/."
    exit -1
fi

result=$(ls Lab3/adjmult/ | grep -e 'adjmult.c' -e 'adjmult.h' -v | wc -l)
if (( $result > 0 )); then
    echo "Failure. There is an extra file or folder present in Lab3/adjmult."
    exit -2
fi

result=$(ls Lab3/codes/ | grep -e 'codes.c' -e 'codes.h' -v | wc -l)
if (( $result > 0 )); then
    echo "Failure. There is an extra file or folder present in Lab3/codes."
    exit -3
fi

result=$(ls Lab3/lib/ | grep -e 'mmath.c' -e 'mmath.h' -e 'mstring.c' -e 'mstring.h' -v | wc -l)
if (( $result > 0 )); then
    echo "Failure. There is an extra file or folder present in Lab3/lib."
    exit -4
fi

result=$(ls Lab3/pascal/ | grep -e 'pascal.c' -e 'pascal.h' -v | wc -l)
if (( $result > 0 )); then
    echo "Failure. There is an extra file or folder present in Lab3/pascal."
    exit -5
fi

result=$(ls Lab3/primes/ | grep -e 'primes.c' -e 'primes.h' -v | wc -l)
if (( $result > 0 )); then
    echo "Failure. There is an extra file or folder present in Lab3/primes."
    exit -6
fi


exit 0
