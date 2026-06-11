# run.ps1 — Compile and run any DSA solution
# Usage: .\run.ps1 <path/to/file.cpp>
# Example: .\run.ps1 03_Sliding_Window/76_MinimumWindowSubstring.cpp

param(
    [Parameter(Mandatory=$true)]
    [string]$File
)

if (-not (Test-Path $File)) {
    Write-Host "❌ File not found: $File" -ForegroundColor Red
    exit 1
}

$BaseName = [System.IO.Path]::GetFileNameWithoutExtension($File)
$OutExe   = "$BaseName.exe"

Write-Host "⚙️  Compiling $File ..." -ForegroundColor Cyan
g++ -std=c++17 -o $OutExe $File

if ($LASTEXITCODE -ne 0) {
    Write-Host "❌ Compilation failed." -ForegroundColor Red
    exit 1
}

Write-Host "▶️  Running $OutExe ...`n" -ForegroundColor Green
& ".\$OutExe"

Remove-Item $OutExe -ErrorAction SilentlyContinue
