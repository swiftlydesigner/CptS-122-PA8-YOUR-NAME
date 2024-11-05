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
# Check if Visual Studio is installed
# $vsInstalled = Get-Command "devenv.exe" -ErrorAction SilentlyContinue

# if (-not $vsInstalled) {
#     Echo-Message "Visual Studio is not installed. Please install Visual Studio before running this script."
#     exit 1
# }

# Echo-Message "Visual Studio is installed. Proceeding with the script..."

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
    $gitPath = "C:\ProgramData\chocolatey\bin"
    [System.Environment]::SetEnvironmentVariable("Path", $env:Path + ";$gitPath", [System.EnvironmentVariableTarget]::Machine)
    Echo-Message "Updated system PATH to include Git."
} else {
    Echo-Message "Git is already installed. Proceeding..."
}

# Disable analytics
$env:VCPKG_DISABLE_METRICS = "1"

# Set the installation directory
$installDir = "$env:USERPROFILE\vcpkg"

# Check if vcpkg is already installed
if (-not (Get-Command "vcpkg" -ErrorAction SilentlyContinue)) {
    # Clone the vcpkg repository to the specified directory
    git clone https://github.com/microsoft/vcpkg.git $installDir

    # Navigate to the vcpkg directory
    cd $installDir

    # Run the bootstrap script to build vcpkg
    .\bootstrap-vcpkg.bat

    # Optional: Add vcpkg to your system PATH
    [System.Environment]::SetEnvironmentVariable("Path", $env:Path + ";$installDir", [System.EnvironmentVariableTarget]::Machine)

    Echo-Message "vcpkg has been installed successfully."
    Echo-Message "You can now use vcpkg to install libraries."
} else {
    Echo-Message "vcpkg is already installed. Proceeding..."
}

# Initialize the answer variable
$answer = ""

# Loop until the user provides a valid answer
while ($answer -ne "yes" -and $answer -ne "no") {
    # Prompt the user to check if they are using ARM64 architecture
    $answer = Read-Host "Are you using ARM64 architecture? (yes/no)"
    
    # Check the user's response
    if ($answer -eq "yes") {
        Write-Host "Installing libpqxx for ARM64..."
        .\vcpkg install libpqxx:arm64-windows
    } elseif ($answer -eq "no") {
        Write-Host "Installing libpqxx for x64..."
        .\vcpkg install libpqxx:x64-windows
    } else {
        Write-Host "Invalid input. Please enter 'yes' or 'no'."
    }
}

.\vcpkg integrate install


# Install libpqxx
Echo-Message "Installing libpqxx..."
cd $vcpkgDir
.\vcpkg install libpqxx --disable-metrics

if ($LASTEXITCODE -ne 0) {
    Echo-Message "Failed to install libpqxx. Please check the output for errors."
    exit 1
}

Echo-Message "libpqxx installed successfully."

# Optional: Set up environment variables (if needed)
$env:VCPKG_ROOT = $vcpkgDir
[System.Environment]::SetEnvironmentVariable("VCPKG_ROOT", $vcpkgDir, [System.EnvironmentVariableTarget]::User)

# Final message
Echo-Message "All installations completed successfully. You can now use vcpkg and libpqxx."