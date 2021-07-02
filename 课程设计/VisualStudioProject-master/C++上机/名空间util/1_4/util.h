#pragma once

namespace util {
	template <class T>
	T cube(T edge) {
		return edge * edge * edge;
	}

	template <class T>
	T square(T side) {
		return side * side;
	}
}
