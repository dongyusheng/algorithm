package search

import (
	"fmt"
	"testing"
)

// go test -v -run="TestBSearch"
func TestBSearch(t *testing.T) {
	a := []int{8, 11, 19, 23, 27, 33, 45, 55, 67, 98}
	value := 33
	index := bsearch(a, len(a), value)
	if index >= 0 {
		t.Logf("find, index:%d", index)
	} else {
		t.Logf("not find")
	}
}

// go test -v -run="TestBSearchFirstEqual"
func TestBSearchFirstEqual(t *testing.T) {
	a := []int{1, 3, 4, 5, 6, 8, 8, 8, 11, 18}
	value := 8
	index := bsearchFirstEqual(a, len(a), value)
	if index >= 0 {
		t.Logf("find, index:%d", index)
	} else {
		t.Logf("not find")
	}
}

// go test -v -run="TestBSearchLastEqual"
func TestBSearchLastEqual(t *testing.T) {
	a := []int{1, 3, 4, 5, 6, 8, 8, 8, 11, 18}
	value := 8
	index := bsearchLastEqual(a, len(a), value)
	if index >= 0 {
		t.Logf("find, index:%d", index)
	} else {
		t.Logf("not find")
	}
}

// go test -v -run="TestBSearchFirstGreaterEqual"
func TestBSearchFirstGreaterEqual(t *testing.T) {
	a := []int{3, 4, 6, 7, 10}
	value := 5
	index := bsearchFirstGreaterEqual(a, len(a), value)
	if index >= 0 {
		t.Logf("find, index:%d", index)
	} else {
		t.Logf("not find")
	}
}

// go test -v -run="TestBSearchFirstGreaterEqual"
func TestBSearchFirstFirstLessEqual(t *testing.T) {
	a := []int{3, 5, 6, 8, 9, 10}
	value := 7
	index := bsearchFirstLessEqual(a, len(a), value)
	if index >= 0 {
		t.Logf("find, index:%d", index)
	} else {
		t.Logf("not find")
	}
}
