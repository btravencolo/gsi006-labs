gcc -o ex02.exe ex02.c

ex02 < ex02.in1 > saida1
ex02 < ex02.in2 > saida2
code -d ex02.out1 saida1&
code -d ex02.out2 saida2&
