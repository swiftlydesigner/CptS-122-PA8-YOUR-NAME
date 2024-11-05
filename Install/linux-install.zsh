!/bin/zsh

# Function to display a message and exit
function exit_with_message {
    echo "$1"
    exit 1
}

# Inform the user about the risks and requirements
echo "WARNING: You are installing software at your own risk. This will install libpqxx, and postgresql."
echo "Only use this script if you are using CLion natively on your Linux machine."
read -p "Are you using CLion? (yes/no): " response

if [[ "$response" != "yes" ]]; then
    exit_with_message "Exiting the script. Please use CLion or another OS."
fi

# Check for package manager
if command -v apt &> /dev/null; then
    PACKAGE_MANAGER="apt"
    echo "Using APT package manager."
elif command -v dnf &> /dev/null; then
    PACKAGE_MANAGER="dnf"
    echo "Using DNF package manager."
else
    exit_with_message "No compatible package manager found. Please install APT or DNF."
fi

# Update package manager
echo "Updating package manager..."
if [[ "$PACKAGE_MANAGER" == "apt" ]]; then
    sudo apt update
elif [[ "$PACKAGE_MANAGER" == "dnf" ]]; then
    sudo dnf check-update
fi

# Install C++ compiler and development tools
echo "Installing C++ compiler and development tools..."
if [[ "$PACKAGE_MANAGER" == "apt" ]]; then
    sudo apt install -y build-essential
elif [[ "$PACKAGE_MANAGER" == "dnf" ]]; then
    sudo dnf groupinstall -y "Development Tools"
fi

# Install PostgreSQL 15
echo "Installing PostgreSQL 15..."
if [[ "$PACKAGE_MANAGER" == "apt" ]]; then
    # Add PostgreSQL repository for Ubuntu
    sudo sh -c 'echo "deb http://apt.postgresql.org/pub/repos/apt/ $(lsb_release -cs)-pgdg main" > /etc/apt/sources.list.d/pgdg.list'
    wget --quiet -O - https://www.postgresql.org/media/keys/ACCC4CF8.asc | sudo apt-key add -
    sudo apt update
    sudo apt install -y postgresql-15 postgresql-client-15 postgresql-contrib
elif [[ "$PACKAGE_MANAGER" == "dnf" ]]; then
    sudo dnf install -y postgresql15 postgresql15-server
fi

if [[ $? -ne 0 ]]; then
    exit_with_message "Failed to install PostgreSQL 15. Please check the output for errors."
fi

echo "PostgreSQL 15 installed successfully."

# Install libpqxx
echo "Installing libpqxx..."
if [[ "$PACKAGE_MANAGER" == "apt" ]]; then
    sudo apt install -y libpqxx-dev
elif [[ "$PACKAGE_MANAGER" == "dnf" ]]; then
    sudo dnf install -y libpqxx-devel
fi

if [[ $? -ne 0 ]]; then
    exit_with_message "Failed to install libpqxx. Please check the output for errors."
fi

echo "libpqxx installed successfully."

# Install CMake
echo "Installing CMake..."
if [[ "$PACKAGE_MANAGER" == "apt" ]]; then
    sudo apt install -y cmake
elif [[ "$PACKAGE_MANAGER" == "dnf" ]]; then
    sudo dnf install -y cmake
fi

if [[ $? -ne 0 ]]; then
    exit_with_message "Failed to install CMake. Please check the output for errors."
fi

echo "CMake installed successfully."

echo "All installations completed successfully."
