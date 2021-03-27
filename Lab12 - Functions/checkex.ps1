
if ($Args.Count -eq 0) {
    Write-Output "Indique qual exercicio voce deseja testar:"
    Write-Output "Exemplo:"
    Write-Output "checkex ex02 `n"
    return -1
}

   
$base = $args[0]

$base_executable = "./" + $base + ".exe"
$base_source = "./" + $base + ".c"
$base_data = ".data/"
$base_input = "./" + $base_data  + $base + "_t*.in"
#Write-Output "Exercise: " $base_executable

Write-Output "Compilando: gcc -o $($base_executable) $($base_source)" 
gcc -o $base_executable $base_source

# verificando se a compilação funcionou
if ( -not $?) {
    Write-Output "Erro ao compilar"
    return -2
}


foreach ($fn in Get-Item $base_input) {
    $fn_in = $base_data + $fn.Name
    $fn_out = $fn_in -replace ".in", ".out"
    #Write-Output $fn_in 
    #Write-Output $fn_out

    #Write-Output "========= entrada  ========="
    #Get-Content $fn_in
    #Write-Output "========= saida esperada ========="
    #Get-Content $fn_out
    #Write-Output ""
    #Write-Output "========= chamando o seu programa ========="
    $saida = Get-Content $fn_in | & $base_executable
    $comp = Compare-Object (Get-Content $fn_out) ($saida)
    if ($comp) { 
        Write-Output "Falhou: " $fn_in         
        Write-Output $comp
    }
    else {
        Write-Output "Sucesso: " $fn_in
    }
    #    & $strcall
}

#$base_input = $base + ".in1"
#$base_output = $base + ".out1"
#Get-Content $base_input | & $base_executable | Out-File -Encoding utf8 .\saida1
#Compare-Object (Get-Content $base_output) (Get-Content .\saida1)

#Write-Output "Test #2" 
#Get-Content .\ex02.in2 | .\ex02 | Out-File -Encoding utf8 .\saida2
#Compare-Object (Get-Content .\ex02.out2) (Get-Content .\saida2)

# ex02 < ex02.in1 > saida1
#ex02 < ex02.in2 > saida2
#code -d ex02.out1 saida1 
#pause
#code -d ex02.out2 saida2

