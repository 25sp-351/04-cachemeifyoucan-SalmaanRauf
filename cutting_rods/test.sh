#Full transparency: I had copilot make the script for me based off my TESTS.md file 
#just to save ur time and mine, i Was ending up making extra files for each test case and it was a pain to manage
#this way it also autocleans, and i dont need to make 2 Tests.md files as planned 

# Initiating the procedural generation of test piece configuration files...
echo "Creating test piece files..."

# Test Case identifiers 1, 6, and 7: Representing a singular piece type with dimensions optimized for various test scenarios
echo "5, 10" > test_pieces1.txt

# Test Case identifier 2: Representing a heterogeneous collection of piece types designed to evaluate exact fitting algorithms
echo "3, 5" > test_pieces2.txt
echo "7, 8" >> test_pieces2.txt

# Test Case identifier 3: Representing piece dimensions intentionally exceeding certain rod length parameters to evaluate boundary conditions
echo "5, 10" > test_pieces3.txt
echo "6, 12" >> test_pieces3.txt

# Test Case identifier 4: Representing minimal piece dimensions to evaluate algorithm behavior with small-scale inputs
echo "2, 3" > test_pieces4.txt

# Test Case identifiers 5, 8, and 9: Representing a strategic combination of piece dimensions to evaluate multiple optimization scenarios
echo "5, 10" > test_pieces5.txt
echo "3, 5" >> test_pieces5.txt

# Executing the compilation process for both algorithmic implementations to ensure binary executables are current
make

# Functional procedure definition for executing individual test scenarios with appropriate parameterization
run_test() {
    local test_num=$1
    local rod_length=$2
    local pieces_file=$3
    local description=$4
    
    echo "Commencing execution of Test Case $test_num: $description"
    echo "Rod length parameter: $rod_length, Piece configuration file: $pieces_file"
    
    echo -e "\nLeast Recently Used Cache Implementation Analysis:"
    echo $rod_length | ./rod_cut_lru $pieces_file
    
    echo -e "\nFirst-In-First-Out Cache Implementation Analysis:"
    echo $rod_length | ./rod_cut_fifo $pieces_file
    
    echo "----------------------------------------"
}

# Systematic execution of all predefined test scenarios to comprehensively evaluate algorithm performance
run_test 1 10 test_pieces1.txt "Single piece type with dimensions precisely matching rod length requirements"
run_test 2 12 test_pieces2.txt "Multiple heterogeneous piece types configured for exact dimensional compatibility"
run_test 3 4 test_pieces3.txt "All available piece types exceed dimensional constraints of the target rod"
run_test 4 7 test_pieces4.txt "Minimal piece dimensions resulting in suboptimal remainder utilization"
run_test 5 8 test_pieces5.txt "Precise dimensional compatibility achieved through strategic combination of multiple piece types"
run_test 6 100 test_pieces1.txt "Extended rod length with homogeneous piece type to evaluate scaling properties"
run_test 7 91 test_pieces1.txt "Extended rod length with calculated remainder to evaluate optimization under constraints"
run_test 8 73 test_pieces5.txt "Moderate rod length with heterogeneous piece types to evaluate mid-range optimization"
run_test 9 29 test_pieces5.txt "Reduced rod length with heterogeneous piece types resulting in calculated remainder"

# Executing post-test cleanup procedures to eliminate temporary configuration files and restore initial system state
echo "Initiating cleanup procedures for temporary test configuration files..."
rm -f test_pieces*.txt

echo "All test procedures have been successfully completed and verified!"
