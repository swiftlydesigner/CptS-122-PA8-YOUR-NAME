!/bin/zsh

# Function to display a message and exit
function exit_with_message {
    echo "$1"
    exit 1
}

# Inform the user about the risks and requirements
echo "WARNING: You are installing software at your own risk. This will install Homebrew, libpqxx, and postgresql."
echo "NOTE: If you are installing Homebrew for the first time, you must run from a user on the sudoers list."
echo "Only use this script if you are using Xcode or CLion natively on your Mac."
read -p "Are you using Xcode or CLion? (yes/no): " response

if [[ "$response" != "yes" ]]; then
    exit_with_message "Exiting the script. Please use the correct install script."
fi

echo "Checking if Homebrew is installed..."
if ! command -v brew &> /dev/null; then
    echo "Homebrew is not installed. Installing Homebrew..."
    
    # Install Homebrew
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    
    if [[ $? -ne 0 ]]; then
        exit_with_message "Failed to install Homebrew. Please check your internet connection and try again."
    fi
    
    echo "Homebrew installed successfully."
else
    echo "Homebrew is already installed."
fi

# Update Homebrew
echo "Updating Homebrew..."
brew update

# Install PostgreSQL 15
echo "Installing PostgreSQL 15..."
brew install postgresql@15

if [[ $? -ne 0 ]]; then
    exit_with_message "Failed to install PostgreSQL 15. Please check the output for errors."
fi

echo "PostgreSQL 15 installed successfully."

# Install libpqxx
echo "Installing libpqxx..."
brew install libpqxx

if [[ $? -ne 0 ]]; then
    exit_with_message "Failed to install libpqxx. Please check the output for errors."
fi

echo "libpqxx installed successfully."

# Install CMake
echo "Installing CMake..."
brew install cmake

if [[ $? -ne 0 ]]; then
    exit_with_message "Failed to install CMake. Please check the output for errors."
fi

echo "CMake installed successfully."

echo "All installations completed successfully. Now, you may open and use the Xcode or CLion Project."
