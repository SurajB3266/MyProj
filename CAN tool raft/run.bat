@echo off
set "prefix1=rx_list_"
set "prefix2=tx_list_"
set "prefix3=data"
set "prefix4=all"
mkdir "%cd%\internal\excelfiles"
mkdir "%cd%\output\arxml"
mkdir "%cd%\output\Ccode"
mkdir "%cd%\internal\Rte"

set "file_location=%cd%\internal\excelfiles"

for /f "delims=" %%f in ('dir /b /a-d "%file_location%\%prefix1%*" 2^>nul') do (
    del "%file_location%\%%f"
)

for /f "delims=" %%f in ('dir /b /a-d "%file_location%\%prefix2%*" 2^>nul') do (
    del "%file_location%\%%f"
)
for /f "delims=" %%f in ('dir /b /a-d "%file_location%\%prefix3%*" 2^>nul') do (
    del "%file_location%\%%f"
)
for /f "delims=" %%f in ('dir /b /a-d "%file_location%\%prefix4%*" 2^>nul') do (
    del "%file_location%\%%f"
)
echo Files with prefix "%prefix1%", "%prefix2%" ,"%prefix3%", %prefix4% have been deleted from "%file_location%"
set "current_dir=%cd%"
echo Current working directory is: %current_dir%
start /B python "%current_dir%\notebook.py" 
pause

