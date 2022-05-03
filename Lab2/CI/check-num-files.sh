#!/bin/bash

result=$(ls Lab2/ | grep -e 'coins' -e 'power' -e 'triangle' -v | wc -l)

if (( $result > 0 )); then
    echo "Failure. There is an extra file or folder present in Lab2/."
    exit -1
fi

result=$(ls Lab2/coins/ | grep -e 'coins.c' -e 'coins.h' -v | wc -l)
if (( $result > 0 )); then
    echo "Failure. There is an extra file or folder present in Lab2/coins."
    exit -2
fi

result=$(ls Lab2/power/ | grep -e 'power.c' -e 'power.h' -v | wc -l)
if (( $result > 0 )); then
    echo "Failure. There is an extra file or folder present in Lab2/power."
    exit -3
fi

result=$(ls Lab2/triangle/ | grep -e 'triangle.c' -e 'triangle.h' -v | wc -l)
if (( $result > 0 )); then
    echo "Failure. There is an extra file or folder present in Lab2/triangle."
    exit -4
fi

exit 0
