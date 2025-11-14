#!/bin/bash

# STL Containers Module - Compilation Script
# Platform: Linux/macOS
# Compiler: g++ or clang++

echo "=========================================="
echo "STL Containers - Compiling All Examples"
echo "=========================================="
echo ""

# Configuration
COMPILER="g++"
STD="c++17"
FLAGS="-Wall -Wextra -O2"
SUCCESS_COUNT=0
FAIL_COUNT=0
TOTAL_COUNT=0

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Check if compiler exists
if ! command -v $COMPILER &> /dev/null; then
    echo -e "${RED}Error: $COMPILER not found${NC}"
    echo "Please install g++ or modify the COMPILER variable in this script"
    exit 1
fi

echo "Compiler: $COMPILER"
echo "Standard: $STD"
echo "Flags: $FLAGS"
echo ""

# Find and compile all .cpp files
while IFS= read -r -d '' file; do
    ((TOTAL_COUNT++))

    # Get output filename (remove .cpp extension)
    output="${file%.cpp}"

    echo -e "${YELLOW}[$TOTAL_COUNT] Compiling: $file${NC}"

    # Compile
    if $COMPILER -std=$STD $FLAGS "$file" -o "$output" 2>&1; then
        echo -e "${GREEN}✅ Success: $file${NC}"
        ((SUCCESS_COUNT++))
    else
        echo -e "${RED}❌ Failed: $file${NC}"
        ((FAIL_COUNT++))
    fi
    echo ""
done < <(find . -name "*.cpp" -print0 | sort -z)

# Summary
echo "=========================================="
echo "Compilation Summary"
echo "=========================================="
echo "Total Files:     $TOTAL_COUNT"
echo -e "${GREEN}Successful:      $SUCCESS_COUNT${NC}"
if [ $FAIL_COUNT -gt 0 ]; then
    echo -e "${RED}Failed:          $FAIL_COUNT${NC}"
else
    echo "Failed:          $FAIL_COUNT"
fi
echo "=========================================="

# Exit with appropriate code
if [ $FAIL_COUNT -eq 0 ]; then
    echo -e "${GREEN}✅ All files compiled successfully!${NC}"
    echo ""
    echo "To run examples:"
    echo "  ./01_SequenceContainers/VectorExample"
    echo "  ./02_AssociativeContainers/SetExample"
    echo "  ... etc"
    exit 0
else
    echo -e "${RED}❌ Some files failed to compile.${NC}"
    echo "Please check the error messages above."
    exit 1
fi

