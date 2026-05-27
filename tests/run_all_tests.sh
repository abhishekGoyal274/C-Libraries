#!/bin/bash

set -e

echo "========================================"
echo "RUNNING ALL TESTS"
echo "========================================"

echo ""
echo "Running Dynamic Array Tests..."
./executables/test_dynamic_array

echo ""
echo "Running Bloom Filter Tests..."
./executables/test_bloom_filter

echo ""
echo "Running Trie Tests..."
./executables/test_trie

echo ""
echo "Running Disjoint Set Tests..."
./executables/test_disjoint_set

echo ""
echo "Running Segment Tree Tests..."
./executables/test_segment_tree

echo ""
echo "========================================"
echo "ALL TESTS PASSED SUCCESSFULLY"
echo "========================================"