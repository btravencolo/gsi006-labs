#!/bin/bash
./ex02 < ./ex02.in1 > ./saida1
#diff saida1 ex02.out1
code -d ex02.out1 saida1
