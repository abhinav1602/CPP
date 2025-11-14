# STL Containers Module - Compilation Script
# Platform: Windows
# Compiler: g++ (MinGW-w64 or MSYS2)

Write-Host "==========================================" -ForegroundColor Cyan
Write-Host "STL Containers - Compiling All Examples" -ForegroundColor Cyan
Write-Host "==========================================" -ForegroundColor Cyan
Write-Host ""

# Configuration
$Compiler = "g++"
$Standard = "c++17"
$Flags = "-Wall", "-Wextra", "-O2"
$SuccessCount = 0
$FailCount = 0
$TotalCount = 0

# Check if compiler exists
try {
    $null = & $Compiler --version 2>&1
} catch {
    Write-Host "Error: $Compiler not found" -ForegroundColor Red
    Write-Host "Please install MinGW-w64 or MSYS2 and add to PATH" -ForegroundColor Red
    exit 1
}

Write-Host "Compiler: $Compiler"
Write-Host "Standard: $Standard"
Write-Host "Flags: $($Flags -join ' ')"
Write-Host ""

# Find and compile all .cpp files
Get-ChildItem -Recurse -Filter "*.cpp" | Sort-Object FullName | ForEach-Object {
    $TotalCount++
    $File = $_.FullName
    $Output = $File -replace '\.cpp$', '.exe'

    Write-Host "[$TotalCount] Compiling: $File" -ForegroundColor Yellow

    # Build argument list
    $Arguments = @("-std=$Standard") + $Flags + @($File, "-o", $Output)

    # Compile
    try {
        $ErrorOutput = & $Compiler $Arguments 2>&1

        if ($LASTEXITCODE -eq 0) {
            Write-Host "✅ Success: $File" -ForegroundColor Green
            $SuccessCount++
        } else {
            Write-Host "❌ Failed: $File" -ForegroundColor Red
            Write-Host $ErrorOutput -ForegroundColor Red
            $FailCount++
        }
    } catch {
        Write-Host "❌ Failed: $File" -ForegroundColor Red
        Write-Host $_.Exception.Message -ForegroundColor Red
        $FailCount++
    }

    Write-Host ""
}

# Summary
Write-Host "==========================================" -ForegroundColor Cyan
Write-Host "Compilation Summary" -ForegroundColor Cyan
Write-Host "==========================================" -ForegroundColor Cyan
Write-Host "Total Files:     $TotalCount" -ForegroundColor White
Write-Host "Successful:      $SuccessCount" -ForegroundColor Green
if ($FailCount -gt 0) {
    Write-Host "Failed:          $FailCount" -ForegroundColor Red
} else {
    Write-Host "Failed:          $FailCount" -ForegroundColor White
}
Write-Host "==========================================" -ForegroundColor Cyan

# Exit with appropriate code
if ($FailCount -eq 0) {
    Write-Host "✅ All files compiled successfully!" -ForegroundColor Green
    Write-Host ""
    Write-Host "To run examples:" -ForegroundColor Cyan
    Write-Host "  .\01_SequenceContainers\VectorExample.exe"
    Write-Host "  .\02_AssociativeContainers\SetExample.exe"
    Write-Host "  ... etc"
    exit 0
} else {
    Write-Host "❌ Some files failed to compile." -ForegroundColor Red
    Write-Host "Please check the error messages above." -ForegroundColor Yellow
    exit 1
}

