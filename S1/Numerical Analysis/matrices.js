// Multiply 2 matrices
const multiply = (A, B) => {
	var aNumRows = A.length,
		aNumCols = A[0].length,
		bNumCols = B[0].length,
		product = new Array(aNumRows)
	for (var i = 0; i < aNumRows; ++i) {
		product[i] = new Array(bNumCols)
		for (var j = 0; j < bNumCols; ++j) {
			product[i][j] = 0
			for (var k = 0; k < aNumCols; ++k) {
				product[i][j] += A[i][k] * B[k][j]
			}
		}
	}
	return product
}

// convert Ax = b to augmented matrix
const augment = (A, b) => {
	i = 0
	for (let row of A) {
		row.push(b[i])
		i++
	}
	return A
}
// Solve triangular matrices
const solveUpper = (U, b) => {
	let zeros = []
	aug = augment(U, b)
	for (let i = aug.length - 1; i >= 0; i--) {
		zeros[i] = aug[i][aug.length] / aug[i][i]
		for (let j = i - 1; j >= 0; j--) {
			aug[j][aug.length] -= aug[j][i] * zeros[i]
		}
	}
	return zeros.map((e) => Number(e.toFixed(2)) + 0)
}
const solveLower = (L, b) => {
	let zeros = new Array(L.length)
	for (let i = 0; i < L.length; i++) {
		zeros[i] = b[i]
		for (let j = 0; j < i; j++) {
			zeros[i] -= zeros[j] * L[i][j]
		}
	}
	return zeros.map((e) => Number(e.toFixed(2)) + 0)
}

// Row-echelon form
const ref = (aug) => {
	for (let i = 0; i < aug.length; i++) {
		// Get the pivot row
		pivot = Math.abs(aug[i][i])
		pivotRow = i
		for (let j = i + 1; j < aug.length; j++) {
			if (Math.abs(aug[j][i]) > pivot) {
				pivot = aug[j][i]
				pivotRow = j
			}
		}
		// Swap the current with the pivot row
		for (let j = i; j <= aug.length; j++) {
			let tmp = aug[pivotRow][j]
			aug[pivotRow][j] = aug[i][j]
			aug[i][j] = tmp
		}
		// Row-echelon form
		for (let j = i + 1; j < aug.length; j++) {
			let c = aug[j][i] / aug[i][i]
			for (let k = i; k <= aug.length; k++) {
				aug[j][k] -= c * aug[i][k]
			}
		}
	}
	let ref = new Array(aug.length)
	for (let i = 0; i < aug.length; ++i) {
		ref[i] = new Array(aug.length + 1)
		for (let j = 0; j < aug.length + 1; ++j) {
			ref[i][j] = aug[i][j]
		}
	}
	return ref
}

// Returns the transpose of a square matrix
const transpose = (mat) => {
	let mT = mat.slice().map((e) => e.slice())
	for (let i = 0; i < mat.length; i++) {
		for (let j = 0; j < mat.length; j++) {
			mT[i][j] = mat[j][i]
		}
	}
	return mT
}

// Compares two matrices
const compare = (mat1, mat2) => {
	for (let i = 0; i < mat1.length; i++) {
		for (let j = 0; j < mat1.length; j++) {
			if (mat1[i][j] !== mat2[i][j]) {
				return false
			}
		}
	}
	return true
}

// Deteminant of a matrix
const determinant = (matrix) => {
	const aug = augment(matrix, [0, 0, 0])
	const ech = ref(aug)
	let det = 1
	for (let i = 0; i < ech.length; i++) {
		det *= ech[i][i]
	}
	return det
}

// Has the matrix a dominant diagonal or not?
const dominantDiagonal = (matrix) => {
	for (let i = 0; i < matrix.length; i++) {
		let diagonal = Math.abs(matrix[i][i])
		let sum = 0
		for (let j = 0; j < matrix.length; j++) {
			sum += Math.abs(matrix[i][j])
		}
		if (sum - diagonal > diagonal) return false
	}
	return true
}

module.exports = {
	multiply,
	augment,
	solveUpper,
	solveLower,
	ref,
	transpose,
	compare,
	determinant,
	dominantDiagonal,
}
