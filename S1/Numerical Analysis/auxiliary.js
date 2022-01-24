// convert numbers to subscript
const subscript = (num) => {
	const subs = ['₀', '₁', '₂', '₃', '₄', '₅', '₆', '₇', '₈', '₉']
	let str = num.toString()
	for (let i = 0; i < 10; i++) {
		str = str.replace(i.toString(), subs[i])
	}
	return str
}

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
	for (row of A) {
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

const formatMatrixRow = (row) => {
	var outStr = ''
	if (row.length === 1) {
		outStr = row[0]
	} else if (row.length === 2) {
		outStr = row.join('   |   ')
	} else if (row.length > 2) {
		outStr = row.slice(0, -1).join('     ') + '   |   ' + row.slice(-1)
	}
	return outStr
}

module.exports = {
	subscript: subscript,
	multiply: multiply,
	augment: augment,
	solveUpper: solveUpper,
	solveLower: solveLower,
	formatMatrixRow: formatMatrixRow,
	ref: ref,
}
