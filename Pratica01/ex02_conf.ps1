
$base =  $args[0]
$base_executable =  $base + ".exe"
$base_source = $base + ".c"
Write-Output "Exercise: " $base_executable

Write-Output "Compilando: gcc -o ex02.exe ex02.c" 
gcc -o $base_executable $base_source
Write-Output %errorlevel%

# foreach ($fn in Get-ChildItem))
Write-Output "Test #1" 
$base_input = $base + ".in1"
$base_output = $base + ".out1"
Get-Content $base_input |& $base_executable | Out-File -Encoding utf8 .\saida1
Compare-Object (Get-Content $base_output) (Get-Content .\saida1)

#Write-Output "Test #2" 
#Get-Content .\ex02.in2 | .\ex02 | Out-File -Encoding utf8 .\saida2
#Compare-Object (Get-Content .\ex02.out2) (Get-Content .\saida2)

# ex02 < ex02.in1 > saida1
#ex02 < ex02.in2 > saida2
#code -d ex02.out1 saida1 
#pause
#code -d ex02.out2 saida2
