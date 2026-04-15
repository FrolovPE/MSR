#!/bin/bash

APP=./a.out
OUT=result_all.txt

A=1
B=3
C=1
D=3

EPS=1e-14
MI=100

: > "$OUT"

for P in 1 2 4
do
    for K in 0 1 2 3 4 5 6
    do
        for NX in 5 1000 10000 
        do
            for NY in 5 1000 1000
            do
                echo "==================================================" | tee -a "$OUT"
                echo "RUN: $APP $A $B $C $D $NX $NY $K $EPS $MI $P" | tee -a "$OUT"
                echo "==================================================" | tee -a "$OUT"

                $APP $A $B $C $D $NX $NY $K $EPS $MI $P >> "$OUT" 2>&1

                echo "" >> "$OUT"
            done
        done
    done
done

echo "Done. Results saved to $OUT"
