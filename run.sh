#!/usr/local/bin/bash

runai() {
  i="0"
  while [ $i -lt 1000000000 ]
  do
    eval ./ai $i $i | tee -a output.csv
    i=$[$i+2500000]
  done
}
