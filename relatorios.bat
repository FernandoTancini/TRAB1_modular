@echo off
@CHOICE /C:123 /m "1:Julia 2:Fernando 3:Suemy  "

IF ERRORLEVEL 3 GOTO sue
IF ERRORLEVEL 2 GOTO fer
IF ERRORLEVEL 1 GOTO jul
GOTO end

:sue
start Relatorios/RELATORIO-SuemyInagaki.txt
GOTO end

:fer
start Relatorios/RELATORIO-FernandoTancini.txt
GOTO end

:jul
start Relatorios/RELATORIO-JuliaRocha.txt
:end
exit