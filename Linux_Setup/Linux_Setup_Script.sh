#!/bin/bash

# Linux Initial Setup includes all the basic packages and Setup C/C++ for Sublime
# Use it by running: chmod +x Linux_Setup_Script.sh && ./Linux_Setup_Script.sh
# Description:
# This script installs various software packages and development tools, sets up Flatpak and repositories,
# clones a Git repository, configures Sublime Text with custom build systems and workspace files,
# and performs system cleanup. It also includes prompts for rebooting the system upon completion.
# Installed Applications:
# 1. Preload - Speeds up boot and app launch times.
# 2. GParted - Disk partition editor.
# 3. VLC - Versatile media player.
# 4. dconf-editor - GNOME configuration editor.
# 5. Build-essential - Tools for compiling software.
# 6. Synaptic - Graphical package manager.
# 7. Flatpak - System for sandboxed apps.
# 8. CopyQ - Clipboard manager.
# 9. Htop - Interactive process viewer.
# 10. Net-tools - Basic network tools.
# 11. Timeshift - Backup utility.
# 12. Git - Version control system.
# 13. Uget - Download manager.
# 14. GNOME Clocks - Multi-timezone clock app.
# 15. Visual Studio Code - Code editor.
# 16. Google Chrome - Web browser.
# 17. Sublime Text - Advanced text editor.
# 18. Node.js & npm - JavaScript runtime and package manager.
# 19. Python 3 & pip - Python language and package installer.
# 20. Boot Repair - Repair boot issues.
# 21. Microsoft Edge - Web browser.

# Update package list and install additional software packages
echo "Updating package list and installing additional software packages..."
sudo apt update
sudo apt install -y preload gparted vlc dconf-editor build-essential synaptic flatpak copyq htop net-tools timeshift git uget gnome-clocks apt-transport-https nodejs python3 python3-pip

# Add the Flathub repository for Flatpak
echo "Adding Flathub repository for Flatpak..."
flatpak --user remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo

# Install Visual Studio Code
echo "Installing Visual Studio Code..."
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.gpg
sudo install -o root -g root -m 644 microsoft.gpg /etc/apt/trusted.gpg.d/
echo "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main" | sudo tee /etc/apt/sources.list.d/vscode.list
sudo apt update
sudo apt install -y code

# Install Google Chrome
echo "Downloading and installing Google Chrome..."
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo dpkg -i google-chrome-stable_current_amd64.deb
sudo apt install -f -y  # Fix any dependency issues

# Install Sublime Text
echo "Downloading and installing Sublime Text..."
wget -qO - https://download.sublimetext.com/sublimehq-pub.gpg | sudo apt-key add -
echo "deb https://download.sublimetext.com/ apt/stable/" | sudo tee /etc/apt/sources.list.d/sublime-text.list
sudo apt update
sudo apt install -y sublime-text

# Install Microsoft Edge
echo "Downloading and installing Microsoft Edge..."
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.gpg
sudo install -o root -g root -m 644 microsoft.gpg /etc/apt/trusted.gpg.d/
echo "deb [arch=amd64] https://packages.microsoft.com/repos/edge stable main" | sudo tee /etc/apt/sources.list.d/microsoft-edge.list
sudo apt update
sudo apt install -y microsoft-edge-stable

# Install Boot Repair
echo "Installing Boot Repair..."
sudo add-apt-repository -y ppa:yannubuntu/boot-repair
sudo apt update
sudo apt install -y boot-repair

# Create directories for your coding projects
echo "Creating directories for coding projects..."
mkdir -p "$HOME/Desktop/Code/IO"

# Create empty files within the IO directory
echo "Creating input and output programming files..."
touch "$HOME/Desktop/Code/IO/input.txt" "$HOME/Desktop/Code/IO/output.txt" "$HOME/Desktop/Code/IO/coutput.txt"

# Clone the repository
echo "Cloning repository..."
mkdir -p "$HOME/Desktop/Code/GitDir"
git clone https://github.com/partho-das/CompetitiveProgrmming.git "$HOME/Desktop/Code/GitDir/"

# Copy Sublime Text build files and workspace to the Sublime Text User directory
echo "Copying Sublime Text configuration files..."
SOURCE_FILES_DIR="$HOME/Desktop/Code/GitDir/CompetitiveProgrmming/Build_Sublime"
CONFIG_DIR="$HOME/.config/sublime-text/Packages/User"
mkdir -p "$CONFIG_DIR"
cp "$SOURCE_FILES_DIR/"*.sublime-build "$CONFIG_DIR/"
cp "$SOURCE_FILES_DIR/git_Desktop_IO.sublime-workspace" "$CONFIG_DIR/"

# Clean up
echo "Cleaning up..."
rm google-chrome-stable_current_amd64.deb microsoft.gpg
sudo apt autoremove -y
sudo apt autoclean -y

# Final update to ensure everything is up to date
sudo apt update

# Print a completion message
echo "Installation and setup complete!"

# Prompt for reboot
read -p "Enter 'y' to reboot now or any other key to exit: " choice
if [ "$choice" = "y" ]; then
    echo "Rebooting..."
    sudo reboot
else
    echo "Reboot canceled. Please reboot the system manually to complete the setup."
fi
