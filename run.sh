#!/usr/local/bin/bash

run() {
  i="0"
  while [ $i -lt 1000000000 ]
  do
    eval ./ai $i $i | tee output.csv
    i=$[$i+10000000]
  done
}
