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

Echo-Message "INFO: You will be installing choco [pkg manager], PostgreSQL [library], vcpkg [pkg manager], git [CLI tool], libpqxx [library]. If you wish to not install the pkg managers and git, PRESS CTRL-C NOW. Then, manually install PostgreSQL and libpqxx."

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

# Install PostgreSQL
Echo-Message "Installing PostgreSQL..."
choco install postgresql -y

if ($LASTEXITCODE -ne 0) {
    Echo-Message "Failed to install PostgreSQL. Please check the output for errors."
    exit 1
}

Echo-Message "PostgreSQL installed successfully."

# Check if Git is installed
if (-not (Get-Command "git" -ErrorAction SilentlyContinue)) {
    Echo-Message "Git is not installed. Installing Git using Chocolatey..."

    # Install Git using Chocolatey
    choco install git -y

    if ($LASTEXITCODE -ne 0) {
        Echo-Message "Failed to install Git. Please check the output for errors."
        exit 1
    }

    Echo-Message "Git installed successfully."

    # Update the system PATH to include Git
    $newPath = "C:\Program Files\Git\bin"
    [Environment]::SetEnvironmentVariable("Path", $env:Path + ";$newPath", "Machine")
    Echo-Message "Updated system PATH to include Git."
} else {
    Echo-Message "Git is already installed. Proceeding..."
}
