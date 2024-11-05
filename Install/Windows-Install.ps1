# Function to display messages
function Echo-Message {
    param (
        [string]$message
    )
    Write-Host "=============================="
    Write-Host $message
    Write-Host "=============================="
}

# Initial message
Echo-Message "WARNING: You are installing software at your own risk. Please ensure you have Visual Studio or a similar development environment installed."

# Check if Visual Studio is installed
$vsInstalled = Get-Command "devenv.exe" -ErrorAction SilentlyContinue

if (-not $vsInstalled) {
    Echo-Message "Visual Studio is not installed. Please install Visual Studio before running this script."
    exit 1
}

Echo-Message "Visual Studio is installed. Proceeding with the script..."

# Check if Chocolatey is installed
if (-not (Get-Command "choco" -ErrorAction SilentlyContinue)) {
    Echo-Message "Chocolatey is not installed. Installing Chocolatey..."

    # Install Chocolatey
    Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.SecurityProtocolType]::Tls12; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))

    if ($LASTEXITCODE -ne 0) {
        Echo-Message "Failed to install Chocolatey. Please check your internet connection and try again."
        exit 1
    }

    Echo-Message "Chocolatey installed successfully."
} else {
    Echo-Message "Chocolatey is already installed. Proceeding..."
}

# Install PostgreSQL 15
Echo-Message "Installing PostgreSQL 15..."
choco install postgresql --version=15 -y

if ($LASTEXITCODE -ne 0) {
    Echo-Message "Failed to install PostgreSQL 15. Please check the output for errors."
    exit 1
}

Echo-Message "PostgreSQL 15 installed successfully."

# Install libpqxx
Echo-Message "Installing libpqxx..."
choco install libpqxx -y

if ($LASTEXITCODE -ne 0) {
    Echo-Message "Failed to install libpqxx. Please check the output for errors."
    exit 1
}

Echo-Message "libpqxx installed successfully."

# Final message
Echo-Message "All installations completed successfully. You can now use PostgreSQL 15 and libpqxx."
