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
        vcpkg install libpqxx:arm64-windows
    } elseif ($answer -eq "no") {
        Write-Host "Installing libpqxx for x64..."
        vcpkg install libpqxx:x64-windows
    } else {
        Write-Host "Invalid input. Please enter 'yes' or 'no'."
    }
}

vcpkg integrate install


# Install libpqxx
Echo-Message "Installing libpqxx..."
vcpkg install libpqxx --disable-metrics

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