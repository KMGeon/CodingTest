# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a competitive programming practice repository focused on algorithm implementations and coding test preparations. The codebase contains C++ solutions for various algorithmic problems, organized by chapters and topics.

## Build System

**Primary Build Tool**: CMake with C++17 standard
- **Build Configuration**: `CMakeLists.txt` configures the project with only `main.cpp` as the executable target
- **Build Directory**: `cmake-build-debug/` contains generated build files
- **Compiler**: clang++ (default system compiler)

### Key Build Commands:
```bash
# Build the project (from project root)
clang++ -std=c++17 main.cpp -o main

# Build specific problem file for testing
clang++ -std=c++17 -o solution ch2/_1B_CountingStar_1.cpp

# Run the main executable
./main

# For development in CLion IDE, use the standard build/run actions
```

## Codebase Architecture

### Directory Structure:
- **Root**: Contains main.cpp (current active solution) and utility files
- **ch2/**: Chapter 2 algorithm problems with multiple solution approaches
- **ch3/**: Chapter 3 problems (currently empty)
- **dfs-bfs/**: Specialized directory for DFS/BFS algorithm implementations
- **cmake-build-debug/**: Build artifacts and executables

### File Naming Conventions:
- `_1B_CountingStar_1.cpp`: Problem identifier with solution variant
- `_1K_1_펠린드롬.cpp`: Korean problem names included for clarity
- Multiple solution files indicate different approaches (e.g., `_1.cpp`, `_2.cpp`)

### Code Patterns and Standards:

#### Standard Header and Optimization:
```cpp
#include <bits/stdc++.h>
using namespace std;

// Performance optimization boilerplate
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```

#### Common Algorithm Patterns:
- **DFS/BFS implementations**: Use adjacency lists `vector<int> adj[V]` and boolean visited arrays
- **Graph traversal**: Standard 4-directional movement arrays `dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}`
- **String processing**: Heavy use of STL containers (map, vector, string manipulation)
- **Array indexing**: Often uses 1-based indexing for graph problems

#### Data Structure Usage:
- Preference for STL containers: `vector`, `map`, `string`
- Fixed-size arrays for performance: `int visited[V]`, `int a[num][num]`
- Global constants for array sizes: `const int V = 10`

## Development Workflow

### Testing Individual Solutions:
1. Copy desired solution to `main.cpp` or compile directly
2. Provide input through stdin
3. Verify output matches expected results

### Adding New Problems:
- Follow the existing naming convention in appropriate chapter directory
- Include problem description and complexity analysis in comments
- Implement multiple approaches when beneficial for learning

### Code Style Guidelines:
- Use descriptive variable names for clarity
- Include complexity analysis in comments when relevant
- Maintain consistent indentation and formatting
- Add Korean comments for problem context when helpful

## Key Implementation Notes

- **Memory management**: Primarily uses stack allocation and STL containers
- **Input/output**: Standard cin/cout with performance optimizations
- **Error handling**: Boundary checking for array access and graph traversal
- **Algorithm focus**: Emphasis on competitive programming techniques and optimal solutions

## Problem Categories Covered

- **String algorithms**: Character counting, palindrome construction
- **Graph algorithms**: DFS, BFS, connected components
- **Array manipulation**: 2D arrays, coordinate transformations
- **Data structure operations**: Maps, vectors, custom sorting

When working with this codebase, prioritize algorithm correctness and efficiency. The code is structured for competitive programming where performance and concise implementation are valued over extensive documentation or complex architectures.