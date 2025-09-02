# Stop of errors
set -e 

# Change to the build folder 
cd ../build 

# Run Cmake Configurations
echo "Running CMake configuration"
cmake ..

# Build the project
echo "Building the project"
cmake --build . 

# Run the project 
echo "Running the project"
./AdventOfCode2024
